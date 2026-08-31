let arrayData = [];

function changeInterface() {
    const display = document.querySelector('#list-display');

    if (arrayData.length === 0) {
        display.innerHTML = "NULL";
        return;
    }

    const stringArray = arrayData.map(num => `[${num}]`).join(' -> ');
    display.innerHTML = `${stringArray} -> NULL`;
}

function insertItem() {
    const value = document.querySelector('#value-input').value;
    arrayData.push(value);
    changeInterface();
}

function removeItem() {
    const value = document.querySelector('#value-input').value;
    if (arrayData.includes(value)) {
        arrayData.pop(value);
        changeInterface();
    } else {
        alert(`Value ${value} was not found in the list!`);
    }
}

function searchItem() {
    const value = document.querySelector('#value-input').value;

    if (arrayData.includes(value)) {
        alert(`Value ${value} was found in the list!`);
    } else {
        alert(`Value ${value} was not found in the list!`);
    }

}

changeInterface();