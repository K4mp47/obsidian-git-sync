## ExpressJs
Command to install express inside a folder

	$ express

Use Pug template and create `.gitignore` file

	$ express --git --view=pug

there is another parameter that you could pass that is `--css=less|stylus` based on the preprocessor of css that you want to use

Create a template using plug is pretty simple
```pug
#banner.page-header
 h1 My page
  p.lead Welcome to my page
```

That return:

```html
<div id="banner" class="page-header"> 
	<h1>My page</h1> 
	<p class="lead">Welcome to my page</p> 
</div>
```

Remember to use `npm install` after `express` command to install the dependencies.

Remember to use this command for a better response from the terminal in term of debug inside express:

	$ DEBUG=myapp:* npm start

---
### Automatic restart
Some services have been developed to monitor application code and restart the pro- cess when they detect that changes have been made. One such service, and the one you’ll use in this book, is nodemon. nodemon wraps the Node application and, other than monitoring for changes, causes no interference. To use nodemon, start by installing it globally, much as you did with Express. Use npm in terminal:

	$ npm install -g nodemon

Instead of `node` run:

	$ nodemon

---
### Structure redefine

Inside the book, after creating a Express Application (remember `npm install -g express express-generator`) we change the structure adding a `app_server` folder, adding `modules` and `controller` folders, moving inside this folder `router` and `views`.

the structure of the express app now looks like:
![[Pasted image 20240705110305.png]]

#### Route definition
```javascript
1 /* GET homepage.*/
2 router.get('/', function(req, res) {
3	  res.render('index', {title: 'Express' });
4 });
```

> line 2: Where the router looks for the url
> line 3: Controller content, albeit very basic right now
> line 3: index = pug file in /views folder

#### MVC concept
![[Pasted image 20240705184642.png]]

controllers located inside the `app_server` folder.

how to require files from the controller? using the `require()` command inside the `index.js` file.

```javascript
const express = require('express'); 
const router = express.Router(); 

const ctrlLocations = require('../controllers/locations');
const ctrlOthers = require('../controllers/others');

/* Locations pages */ 
router.get('/', ctrlLocations.homelist);
router.get('/location', ctrlLocations.locationInfo);
router.get('/location/review/new', ctrlLocations.addReview);

/* Other pages */ 
router.get('/about', ctrlOthers.about);
module.exports = router;
```

#### Mongo DB

Start installing the required packages inside the root folder 

	$ npm i mongoose	 

I made the file `db.js` inside the `models` folder, and i have insert the code to make the express application connect to the mongodb database, in order to run the database and the express application. For a better coding experience, inside the `db.js` file i provide the code to do not manually close the connection with the db.

```javascript
const gracefulShutdown = (msg, callback) => {
    mongoose.connection.close(() => {
        console.log(`Mongoose disconnected through ${msg}`);
        callback();
    });
};

process.once('SIGUSR2', () => {
    gracefulShutdown('nodemon restart', () => {
        process.kill(process.pid, 'SIGUSR2');
    });
});

process.on('SIGINT', () => {
    gracefulShutdown('app termination', () => {
        process.exit(0);
    });
});
```

Mongoose was built specifically as a MongoDB Object Document Modeler (ODM) for Node applications. One key principle is that you can manage your data model from within your applications. You don't have to mess around directly with databases or external frameworks or relational mappers; you can define your data model in the comfort of your application.
