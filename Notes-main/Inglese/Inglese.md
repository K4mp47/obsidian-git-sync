# Struttura test di inglese
- Aim?
	- Explain a concept
- Who is the audience?
	- English teacher
- What is my title?
	- CSRF: Attack and Defense
- Main points?
	- Explain what is CSRF
	- Report example of CRSF
	- Teach how to defence against CSRF
- What i want the audience do?
	- To understand the risk of CSRF and how to prevent this attack

## First phace: Introduction
1. Get the audience attention:
	- Can we start?
	- Let's begin
	- Shall we start?
2. Introduct myself:
	- Good Morning/Afternoon teachers, let me introduce myself.... (1 part complete)
3. Give title  and introduce subject:
	- I plan to speak about...  
	- Today I'm going to talk about...  
	- The subject of my presentation is...  
	- The theme of my talk is...  
	- I've been asked to give you an overview of...
4. Give the purpose, aim, goal of the presentation:
	- What I would like to do today is to explain, or  
		- to illustrate...  
		- to give you the essential background information on...
- Extra:
	-  Announce the outline:
		- I have divided my presentation into X parts: explain parts

## Second phase: Body
All the information about what you decide to expose to the audience.
I talk about CRSF so my body will similar to:
- General explanation of what is CSRF.
- Explanation about what CSRF do and how it work.
- Report reals CSRF example 
- Explain how to defence from CRSF

## Conclusion
Finish of the presentation, inviting a discussion between me and the teachers.


# Ora che le linee guida sono finite iniziamo a vedere come fare questa presentazione:


## Intro
> the intro is there
## Body
## CRSF (Cross Site Request Forgery)
What is CSRF? It's a malicious attack make by criminals that occurs when they can make a target's browser send an HTTP request to another website. For a deep comphrension of how CSRF work, we have to know first how an HTTP request is perform.
The HTTP is a protocol used over the Internet for connect two machine and let them communicate each other.
How this protocol work is quiet simple:
- We have two main figures, client(Bob's browser) and server(banking website)
- The client perform the request to the server, which elaborate the request sending a response to the client based on what it have asked for (banking user's page).
- We can image the request as a file sent to the server from the client with inside information about what the client want to see. It's divide in two parts, header and body. Body contain html code, while header contain all the information that the server needed to resolve the request, as the host, the resource requested, the type of browser used by the client, the cookies used, ecc.

That website then performs an action as through the request were valid and sent by the target. When a CSRF attack is successfull, the attacker is able to modify server-side information and might even take over a user's account. Here is a basic example:
- Bob login into his banking website to check his balance
- When he's finished, Bod checks his email account 
- Bob has an email with a link to a unfamiliar website and clicks the link to see where it leads
- When loaded, the unfamiliar website instructs Bob's browser to make an HTTP request to Bob's banking website,requesting a money transfer from his account to the attacker's
- Bob's banking website receives the HTTP request initiated from the unfamiliar website. But because the banking website doesn't have any CSRF protections, it processes the transfer

## How is possible? Cookies!
It's is possible for the weaknesses in the process website use to authenticate requests. When you visit a website that requires you to log in, usually with a username and password, that site will typically authenticate you. The site will be store that authentication into your browser so you don't have to log in every time you visit a new page on that site. It can store the authentication in two ways: use the basic authentication protocol or a cookie.
I won't focus on basic authentication in this presentation, so let's get a deep introduction of the cookies. Cookies are small files that websites create and store in the user's browser. Websites use cookies for various purpose, as save information about user's history of visited website or user preferences. Inside this cookies there are two very important attributes for security called secure and httponly. Set this attributes to true permit to protect user's privacy, because they permit the browser to send cookies also when visiting HTTP sites and to read cookie only through HTTP and HTTPS request.
To summarize, if the banking site bob visits uses cookies, the site will store his authentication with the following process. Once Bob visits the sites and logs in, the bank will respond to his HTTP request with an HTTP response, which includes a cookie that identifies Bob. In turn, Bob's browser will automatically send that cookie with all other HTTP request to the banking website. After finishing his banking, Bob doesn't log out when he leaves the banking website. Note this important detail, because when you log out, that site respond with an HTTP response that expires your cookie. As a result, you'll have to login again when you return into the site. The malicious website that istructs Bob's browser to make a request to his banking website perform the request using cookie from Bob's browser.
 
## Real Example:
Author: WeSecureApp
URL: https://twitter-commerce.shopifyapps.com/auth/twitter/disconnect/
Source: https://www.hackerone.com/reports/111216/
Date reported: January 17, 2016
Bounty paid: $500

This hacker, or bug hunter, discovered a vulnerability in a Shopify feature that integrated Twitter into the site to let shop owners tweet about their products. The feature also allowed users to disconnect a Twitter account from a connected shop. The URL to disconnect a Twitter account was the following:

	https://twitter-commerce.shopifyapps.com/auth/twitter/disconnect/

As it turns out, visiting this URL would send a request to disconnect the account,as follows:

	 GET /auth/twitter/disconnect HTTP/1.1
	 Host: twitter-commerce.shopifyapps.com
	 User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10.11; rv:43.0) Gecko/20100101 Firefox/43.0
	 Accept: text/html, application/xhtml+xml, application/xml
	 Accept-Language: en-US, en;q=0.5
	 Accept-Encoding: gzip, deflate
	 Refer: https://twitter-commerce.shopifyapps.com/account
	 Cookie: _twitter-commerce_session=REDACTED
	 Connection: keep-alive

but Shopify wasn't validating the legitimacy of the request sent to it, making the URL vulnerable to CSRF. The hunter who found this vulnerability, provided the following proof-of-concept HTML document:
```html
<html>
	<body>
		<img src="https://twitter-commerce.shopifyapps.com/auth/twitter/disconnect/"/>
	</body>
</html>
```

When opened, this HTML document would cause the browser to send an HTTP request to https://twitter-commerce.shopifyapps.com/ through the <img\> tag's **_src_** attribute. If someone with a Twitter account connected to Shopify visited a web page with this <img\> tag, their Twitter account could be disconnected from Shopify. With software as BurpSuite or ZAP, you could have found the vulnerability.

## Defenses Against CSRF Attacks
You can mitigate this vulnerabilities in a number of ways. One of the most popular is the CSRF token. Protected sites require CSRF token when requests are submitted that could potentially alter data. In such a situation, a web application (like Bob's bank) would generate a token with two parts: one that Bod would receive and one that the application would retain. When Bob attempts to make transfer requests, he  would have to submit his token, which the bank would then validate with its side of the token. The design of these token makes them unguessable and only accessible to the specific user they're assigned to (like Bob). Tokens can be included in HTTP request headers, in an HTTP body, or as a  hidden field, as in the following example: 
```html
<form>
	<input type="text" name="from" value="Bob">
	<input type="text" name="to" value="joe">
	<input type="text" name="amount" value="500">
	<input type="hidden" name="csrf" value="lHt7DDDyUNKoHCC66BsPB8aN4p24h=">
	<input type="submit" value="submit">
</form>
```
In this example, the site could get the CSRF token from a cookie, an embedded script on the website, or as part of the content delivered from the site. Regardless of the method, only the target's web browser would know and be able to read the value. Because the attacker couldn't submit the token, they wouldn't be able to successfully submit a request and wouldn't be able to carry out a CSRF attack. You can use other ways to protect sites from this vulnerability. One of them is implement support for a new cookie attribute called samesite.
This attribute can be set as strict or lax. When set as strict, the browser will not send the cookie with any HTTP request that doesn't originate from the site. This includes even simple HTTP request that doesn't originate from the site. For example, if you were logged into Amazon and it used strict samesite cookies, the browser would not submit your cookies if you were following a link from another site. Also, Amazon would not recognize you as logged in until you visited another Amazon web page and the cookies were then submitted. lax value instead istructs browsers to send cookies with initial request. This support the design principle that initial request should never alter data on the server side.

## Bypass CSRF Tokens Stored on the Server  

But what if the site implements CSRF protection via tokens in a wrong way? Here are a few more things that you can try.  

Just because a site uses CSRF tokens doesn’t mean it is validating them  
properly. You could still achieve CSRF with a few modifications of your malicious HTML page.

First, try deleting the token parameter or sending a blank token param-  
eter. For example, this will send the request without a csrf_token parameter:  

	POST /password_change  
	Host: email.example.com  
	Cookie: session_cookie=YOUR_SESSION_COOKIE  
	
	(POST request body)  
	new_password=abc123  

You can generate this request with an HTML form like this:  

```html
<html>  
	<form method="POST" action="https://email.example.com/password_change" id="csrf-form">  
		<input type="text" name="new_password" value="abc123">  
		<input type='submit' value="Submit">  
	</form>  
	<script>document.getElementById("csrf-form").submit();</script>  
</html>
```

This next request will send a blank csrf_token parameter:  

	POST /password_change  
	Host: email.example.com  
	Cookie: session_cookie=YOUR_SESSION_COOKIE  
	
	(POST request body)  
	new_password=abc123&csrf_token=

Deleting the token parameter or sending a blank token often works  
because of a common application logic mistake. Applications sometimes  
check the validity of the token only if the token exists, or if the token  
parameter is not blank.