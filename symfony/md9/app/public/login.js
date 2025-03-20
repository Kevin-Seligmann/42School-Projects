import { clearPost } from "./post.js";

function loginRequest(event){
	event.preventDefault();
	const form = event.target;

	const formData = new FormData(form);
	fetch(form.action, {
		method: "POST",
		body: formData,
	  })
	.then(response => {
		const contentType = response.headers.get('content-type');
        if (contentType && contentType.includes('application/json')) {
            return response.json();
        } else {
            return response.text();
        }
	})
	.then(data => {
		if (data.error)
			alert(data.error);
		else
			document.documentElement.innerHTML = data;
	})
	.catch(error => console.error("Error:", error));
}
window.loginRequest = loginRequest

function registerRequest(event){
	event.preventDefault();
	const form = event.target;
	const formData = new FormData(form);

	fetch(form.action, {
		method: "POST",
		body: formData,
	  })
	.then(response => response.json())
	.then(data => {
			alert(data.response);
		}
	)
	.catch(error => console.error("Error:", error));
}
window.registerRequest = registerRequest

function logoutRequest(event){
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
		const formContainer = document.getElementById('mainFormContainer');
		formContainer.innerHTML = data.form;
		alert(data.response);
	})
	.catch(error => console.error("Error:", error));
}
window.logoutRequest = logoutRequest;
