//Express JS
const express = require('express')
const app = express()

//Serve static files from /public
app.use(express.static('public'))

// Start Server
app.listen(2222,() => console.log('Server running on port 2222!'))
