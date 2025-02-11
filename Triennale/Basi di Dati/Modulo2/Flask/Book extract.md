> Download the example code to check during the creation phase.

**https://github.com/miguelgrinberg/flasky.git**
$\uparrow$ very useful trust me
```bash
git clone https://github.com/miguelgrinberg/flasky.git
cd flasky
git checkout 1a
```
>You need to use a virtual enviroment, because you don't want problem with the library/package that you install
```bash
sudo apt-get install python3-venv
python3 -m venv <dir_name> # usually it's called venv
```
 @ PLEASE USE PYTHON 3
> For activating and using the virtual enviroment
```bash
source venv/bin/activate # linux
venv/Scripts/activate # Windows, trust me you don't want it
```
> If you're using the venv, the terminal print
```
(venv) $
```
> Install python package using pip
```bash
(venv) $ pip install flask
```
```bash
pip freeze # use it for check the package that you've install
```
## Inizialization
All Flask application must create an application instance. This instance is an object of class **Flask**, usally created as follows:
```python
# check __init__ file into the project
from flask import Flask
app = Flask(__name__)
```
\_\_name\_\_  is the correct argument for most Flask application

### How Routes Work
To define a route in a Flask application you'll use the app.route decorator as follow:
```python
@app.route('/')
def index():
	return '<h1>Hello World!</h1>'
```
If you need a parameter on the url:
```python
@app.route('/user/<name>')
def index(name):
	return '<h1>Hello {}!</h1>'.format(name)
```
$\uparrow$ This code ask for the parameter using the dynamic part \<name>. By default these components are strings but can also be of different types like
```python
/user/<int:id>
```
That would match only URLs that have an intefer in the **id** dynamic segment.

### Complete Application Example

hello.py file
```python
from flask import Flask 
app = Flask(__name__) 
@app.route('/') 
def index(): 
	return '<h1>Hello World!</h1>'

@app.route('/user/<name>') 
def user(name): 
	return '<h1>Hello, {}!</h1>'.format(name)
```
##### Development
```bash
export FLASK_APP=hello.py
flask run
```
>!!Important!!
> You can use the *debug mode*, that's a web-based tool that appears in your browser when your application raises an unhandled exception

```bash
export FLASK_APP=hello.py
export FLASK_DEBUG=1
flask run
```
## The Request-Response Cycle
When Flask receive a request from a client, it needs to make a few objects available to the view function that will handle it. A good example is the *request object* 

To avoid cluttering view function with lots of arguments, Flask use *contexts* to temporarily make certain objects globally accessible. Using that, the view functions like the following one can be written:
```python
from flask import request 

@app.route('/') 
def index(): 
	user_agent = request.headers.get('User-Agent') 
	return '<p>Your browser is {}</p>'.format(user_agent)
```
|*Flask context globals*|
|-------|
|![[Pasted image 20240219130909.png]] |
 When the application context is pushed, the current_app and g variables become available to the thread. Likewise, when the request context is pushed, request and session become available as well. If any of these variables are accessed without an active appli‐ cation or request context, an error is generated
```python
>>> from hello import app
>>> from flask import current_app
>>> current_app.name
Traceback (most recent call last):
...
RuntimeError: working outside of application context
>>> app_ctx = app.app_context()
>>> appt_ctx.push()
>>> current_app.name
'hello'
>>> app_ctx.pop()
```
You can dispatch using the URL map inside a Flask application and see what it looks like using the following command:
```python
(venv) $ python 
>>> from hello import app 
>>> app.url_map Map([<Rule '/' (HEAD, OPTIONS, GET) -> index>,
  <Rule '/static/<filename>' (HEAD, OPTIONS, GET) -> static>,
  <Rule '/user/<name>' (HEAD, OPTIONS, GET) -> user>])
```
(Pagina 19)