package main

import (
  "github.com/gin-gonic/gin"
  "net/http"
)

type album struct {
  ID     string  `json:"id"`
  Title  string  `json:"title"`
  Artist string  `json:"artist"`
  Price  float64 `json:"price"`
}

type user struct {
  ID string `json:"id"`
  Dr_rm int `json:"dr_rm"`
  Total_pay float64 `json:"total_pay"`
  //created_at timestamp `json:"created_at"`
}

type drink struct {
  Name string `json:"name"`
  Price float64 `json:"price"`
}

var drinks = []drink{
  {Name: "Water", Price: 0.0},
  {Name: "Coke", Price: 1.99},
  {Name: "Pepsi", Price: 3.99},
}

func addPrizeToUser(c *gin.Context) {
  id := c.Param("id")
  name := c.Param("name")

  var drink drink
  for i := range users {
    if users[i].ID == id {
      if users[i].Dr_rm > 0 {
        users[i].Dr_rm = users[i].Dr_rm - 1
      } else {
        c.IndentedJSON(http.StatusOK, gin.H{"message": "no drinks left"})
        return
      }
      for _, d := range drinks {
        if d.Name == name {
          users[i].Total_pay = users[i].Total_pay + d.Price
          drink = d
          break
          // that if doesn't change values inside the users array
        }
      } 

      c.IndentedJSON(http.StatusOK, drink)
      return
    }
  }

  c.IndentedJSON(http.StatusNotFound, gin.H{"message": "drink not found"})
}

var users = []user{
  {ID: "1", Dr_rm: 3, Total_pay: 0},
  {ID: "2", Dr_rm: 3, Total_pay: 0},
  {ID: "3", Dr_rm: 3, Total_pay: 0},
}

func getUserByID(c *gin.Context) {
  id := c.Param("id")

  for _, a := range users {
    if a.ID == id {
      c.IndentedJSON(http.StatusOK, a)
      return
    }
  }

  c.IndentedJSON(http.StatusNotFound, gin.H{"message": "user not found"})
}

var albums = []album{
  {ID: "1", Title: "Blue Train", Artist: "John Coltrane", Price: 56.99}, 
  {ID: "2", Title: "Jeru", Artist: "Gerry Mulligan", Price: 17.99}, 
  {ID: "3", Title: "Sarah Vaughan and Clifford Brown", Artist: "Sarah Vaughan", Price: 39.99}, 
}

func getAlbums(c *gin.Context) {
  c.IndentedJSON(http.StatusOK, albums)
}

func getAlbumsByID(c *gin.Context) {
  id := c.Param("id")

  for _, a := range albums {
    if a.ID == id {
      c.IndentedJSON(http.StatusOK, a)
      return
    }
  }
  
  c.IndentedJSON(http.StatusNotFound, gin.H{"message": "album not found"})
}

func postAlbums(c *gin.Context) {
  var newAlbum album

  if err := c.BindJSON(&newAlbum); err != nil {
    return
  }

  albums = append(albums, newAlbum)
  c.IndentedJSON(http.StatusCreated, newAlbum)
}

func main() {
  router := gin.Default()

  router.GET("/albums", getAlbums)
  router.GET("/albums/:id", getAlbumsByID)
  router.POST("/albums", postAlbums)

  router.GET("users/:id", getUserByID)
  router.GET("user/:id/:name", addPrizeToUser)
  router.Run("localhost:8080")
}
