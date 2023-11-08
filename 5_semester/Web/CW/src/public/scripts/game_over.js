let score_table = JSON.parse(localStorage["pac_man.score_table"])
score_table.sort(compare)

function compare(left, right)
{
    if (left.score < right.score)
    {
        return 1
    }
    return -1
}

/* Display of the table of records (only the first 5) */
let table = document.getElementById('table')

for (let i = 0; i < Math.min(15, score_table.length); i++)
{
    let result = document.createElement("div")
    result.setAttribute("class", "result")

    let number = document.createElement("div")
    number.setAttribute("class", "number")
    number.innerText = i + 1
    result.appendChild(number)

    let username = document.createElement("div")
    username.setAttribute("class", "name")
    username.innerText = score_table[i].name
    result.appendChild(username)

    let level = document.createElement("div")
    level.setAttribute("class", "level")
    level.innerText = score_table[i].level
    result.appendChild(level)

    let score = document.createElement("div")
    score.setAttribute("class", "score")
    score.innerText = score_table[i].score
    result.appendChild(score)
   
    table.appendChild(result)
}