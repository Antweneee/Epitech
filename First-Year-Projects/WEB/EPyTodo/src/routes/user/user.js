const dotenv = require("dotenv").config()
const express = require("express");
const rout = express.Router()

rout.put('/:id', function(req, res) {
    res.status(200).send('<h1></h1>')
})

rout.delete('/:id', function(req, res) {
    res.status(200).send('<h1>delete id</h1>')
})

module.exports = rout