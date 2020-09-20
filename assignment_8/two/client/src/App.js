import React, { useState } from 'react';
import axios from 'axios';
import './App.css';
const pbkdf2 = require('pbkdf2');

function App() {

    const [username, setUsername] = useState('');
    const [password, setPassword] = useState('');
    const [loggedIn, setLoggedIn] = useState(false);

    const logIn = () => {
        axios.post('http://localhost:5000/auth',
            {
                username: username,
                password: password
            })
            .then(res => {
                localStorage.setItem('bearer', res.headers.authorization);

                const header = {
                    headers: {
                        Authorization: localStorage.getItem('bearer'),
                        'Content-Type': 'application/json;charset=UTF-8',
                        'Access-Control-Allow-Origin': '*'
                    }
                };

                axios.get('http://localhost:5000/hello', header)
                    .then(res => {
                        if (res.status === 200) {
                            console.log('Auth OK');
                            setLoggedIn(true);
                        } else {
                            setLoggedIn(false);
                        }

                    });
            });
    };

    const handleUsername = event => {
        setUsername(event.target.value);
    };

    const handlePassword = event => {
        const salt = 'salt';
        const hash = pbkdf2.pbkdf2Sync(event.target.value, salt, 2048, 15, 'sha512').toString('hex');
        console.log('hash', hash);
        setPassword(hash);
    };


    const handleLoginButton = () => {
        console.log(password);
        console.log('Logging in...');
        logIn()


    };

    const handleRegisterButton = () => {
        console.log('Registering...');
        axios.post('http://localhost:5000/register',
            {
                username: username,
                password: password
            })
            .then(res => {
                (res.status === 200) ? alert(`You've been registered!`) : alert('Something went wrong :/');
            })
            .catch(err => console.log(err));

    };


  return (
    <div className='App'>
        <div>
            <input onChange={handleUsername} placeholder='Username'/>
            <input onChange={handlePassword} type={'password'} placeholder='Password'/>
        </div>

        <div>
            <button onClick={handleRegisterButton} type='button'>Register</button>
            <button onClick={handleLoginButton} type='button'>Login</button>
        </div>

        {loggedIn ? <h1>You're authorized!</h1> : ''}

    </div>

  );
}


export default App;
