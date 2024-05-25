const dotenv = require('dotenv').config();
const express = require('express');
const rout = express.Router();

rout.post('/login', function(req, res) {
    res.status(200).send('<h1>login</h1>')
})

rout.post('/register', function(req, res) {
    res.status(200).send('<h1>register</h1>')
})

module.exports = rout