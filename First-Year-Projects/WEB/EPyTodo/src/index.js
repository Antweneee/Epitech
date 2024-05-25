require('dotenv').config();
const express = require('express');
const app = express();
const port = 8081;
const auth = require('./routes/auth/auth');
const user = require('./routes/user/user');
const todos = require('./routes/todos/todos');
const sql = require('epysql');

app.use('/user', user);
app.use('/', auth);
app.use('/todos', todos);

app.get('/', (req, res) =>
    res.send('Hello World!'))

app.get('/name/:id', function(req, res) {
    var name = req.params.id;
    res.send('Hello ' + name + " !\n");
});

app.get('/date', function(req, res) {
    var datetime = new Date();
    var year = datetime.getFullYear();
    var month = datetime.getMonth() + 1;
    var day = datetime.getDate();
    res.send(year + '-' + month + '-' + day + '\n');
});

const connect = sql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'Antweneee:)',
});

connect.connect((err) => {
    if (err) throw err;
    console.log('connected');
});

app.listen(port, () =>
    console.log(`Example app listening to https://localhost:${port}!`))