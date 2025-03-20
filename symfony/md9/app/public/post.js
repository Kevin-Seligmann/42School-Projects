import {conn} from './websocket.js'

function submitPost(event){
	event.preventDefault();
	const form = event.target;
	const formData = new FormData(form);

	fetch(form.action, {
		method: "POST",
		body: formData,
	  })
	.then(response => response.json())
	.then(data => {
			if (data.error)
				alert(data.error);
			else if (data.errors)
				alert(data.errors.join("\n"));
			else {
				addPostWs(data);
				data.type = "addPost";
				conn.send(JSON.stringify(data));
				alert("Added post");
			}
		}
	)
	.catch(error => console.error("Error:", error));
}
window.submitPost = submitPost;

function viewPost(event){
	event.preventDefault();
	clearPost();

	const form = event.target;
	const formData = new FormData(form);

	fetch(form.action, {
		method: "POST",
		body: formData,
	})
	.then(response => response.json())
	.then(data => {

		const postContainer = document.createElement("div");
		postContainer.setAttribute('id', 'postContainer');

		const header = document.createElement("h2");
		const title = document.createElement("h3");
		const created = document.createElement("p");
		const content = document.createElement("p");
		const deleteForm = document.createElement("form");

		deleteForm.setAttribute('action', `/delete/${data.id}`);
		deleteForm.setAttribute('onsubmit', `deletePost(event)`);
		const button = document.createElement('button');
		button.innerText = "Delete post";
		deleteForm.appendChild(button)

		header.textContent = "Post";
		title.textContent = data.title;
		content.textContent = data.content;
		created.textContent = "Created: " + data.created.date;

		postContainer.appendChild(header);
		postContainer.appendChild(title);
		postContainer.appendChild(content);
		postContainer.appendChild(created);
		postContainer.appendChild(deleteForm);

		document.body.appendChild(postContainer);
	})
	.catch(error => console.error("Error:", error));
}
window.viewPost = viewPost;

function deletePost(event){
	event.preventDefault();
	
	const form = event.target;
	const formData = new FormData(form);

	fetch(form.action, {
		method: "DELETE",
		body: formData,
	})
	.then(response => response.json())
	.then(data => {
		if (data.error)
			alert(data.error)
		else {
			deletePostWs(data)
			alert("Post deleted");
			data.type = "deletePost";
			conn.send(JSON.stringify(data));
		}
	})
	.catch(error => console.error("Error:", error));
}
window.deletePost = deletePost;

function clearPost(){
	const postContainer = document.getElementById("postContainer");

	if (postContainer)
		postContainer.remove();
}

function addPostWs(data){
	const table = document.getElementById('postsContainer');
	const row = table.insertRow();
	const title = row.insertCell(0);
	const created = row.insertCell(1);
	const viewRow = row.insertCell(2);

	row.setAttribute('id', data.id)
	const viewForm = document.createElement("form");

	viewForm.setAttribute('action', `/view/${data.id}`);
	viewForm.setAttribute('onsubmit', `viewPost(event)`);
	const button = document.createElement('button');
	button.innerText = "View post";
	viewForm.appendChild(button);

	viewRow.appendChild(viewForm)
	title.textContent = data.title;
	created.textContent = data.created;
}

function deletePostWs(data){
	clearPost();
	const table = document.getElementById("postsContainer");
	const row = document.getElementById(data.id);
	row.remove();
}

export {clearPost, addPostWs, deletePostWs};
