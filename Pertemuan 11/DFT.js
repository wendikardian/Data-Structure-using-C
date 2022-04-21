
const depthFirstPrintf = (graph, source) => {
    let stack = [source];

    while(stack.length > 0){
        const current = stack.pop()
        // console.log(stack);
        for (let neighbor of graph[current]){
            console.log(neighbor)
            // stack[stack.length] = neighbor
        }
    }
}

const graph = {
    a : ['c', 'b'],
    b : ['b'],
    c : ['e'],
    d : ['f'],
    e : [],
    f : []
}

depthFirstPrintf(graph, 'a')