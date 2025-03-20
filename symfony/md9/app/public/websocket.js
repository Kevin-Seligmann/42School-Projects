import { deletePostWs, addPostWs } from './post.js'

var conn = new WebSocket('ws://127.0.0.1:8080');

conn.onopen = function(e) {
    console.log("Connection established!");
};

conn.onerror = function(e) {
    console.error("WebSocket error:", e);
};

conn.onclose = function(e) {
    console.log("WebSocket closed:", e);
};

conn.onmessage = function(e) {
	const data = JSON.parse(e.data)
	
	if (data.type === "deletePost")
		deletePostWs(data);
	else if (data.type === "addPost")
		addPostWs(data)
	else
    	console.log("WS message from server:", e.data);
};

export { conn }
