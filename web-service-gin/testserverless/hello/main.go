package main

import (
	"context"

	"github.com/aws/aws-lambda-go/events"
	"github.com/aws/aws-lambda-go/lambda"
  "github.com/awslabs/aws-lambda-go-api-proxy/gin"
  "github.com/gin-gonic/gin"
)

// Response is of type APIGatewayProxyResponse since we're leveraging the
// AWS Lambda Proxy Request functionality (default behavior)
//
// https://serverless.com/framework/docs/providers/aws/events/apigateway/#lambda-proxy-integration
var ginLambda *ginadapter.GinLambda 

func init() {
  r := gin.Default()
  r.GET("/hello", func(c *gin.Context) {
    c.JSON(200, gin.H{
      "message": "Hello, World!",
    })
  })

  ginLambda = ginadapter.New(r) 
}
// Handler is our lambda handler invoked by the `lambda.Start` function call
func Handler(ctx context.Context, req events.APIGatewayProxyRequest) (events.APIGatewayProxyResponse, error) {
  return ginLambda.ProxyWithContext(ctx, req)
}

func main() {
	lambda.Start(Handler)
}
