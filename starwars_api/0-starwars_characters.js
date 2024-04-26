#!/usr/bin/node

const request = require('request');

// Function to retrieve movie data from the API
function getMovieData (movieID) {
  return new Promise((resolve, reject) => {
    const url = `https://swapi-api.hbtn.io/api/films/${movieID}`;
    request(url, (error, response, body) => {
      if (!error && response.statusCode === 200) {
        resolve(JSON.parse(body));
      } else {
        reject(error);
      }
    });
  });
}

// Function to retrieve character name from URL
function getCharacterName (characterURL) {
  return new Promise((resolve, reject) => {
    request(characterURL, (error, response, body) => {
      if (!error && response.statusCode === 200) {
        const character = JSON.parse(body);
        resolve(character.name);
      } else {
        reject(new Error('Error fetching character data'));
      }
    });
  });
}

// Function to print character names in the order provided by the API response
async function printCharacterNames (movieID) {
  try {
    const movie = await getMovieData(movieID);
    const characterPromises = movie.characters.map(characterURL => getCharacterName(characterURL));
    const characterNames = await Promise.all(characterPromises);
    characterNames.forEach(name => console.log(name));
  } catch (error) {
    console.log('Error:', error);
  }
}

// Main function
function main () {
  const movieID = process.argv[2];
  if (movieID) {
    printCharacterNames(movieID);
  } else {
    console.log('Usage: node script.js <movieID>');
  }
}

main();
