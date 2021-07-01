// PERIANU LEON-GABRIEL
// IONUT SABAU
// DAN TOMOIU
// CRISTIAN POVIAN




let squareCount = 0;

function addGrid(positions, colors) {
    initialSize = Array.from(positions).length / 2;
    for (let x = -3.5; x <= 3.5; x += .5) {
        positions.push(x, -2, x, 2);
    }
    for (let y = -2; y <= 2; y += .5) {
        positions.push(-3.5, y, 3.5, y);
    }
    for (let i = 0; i < 192 / 4; i++) {
        colors.push(.3, .3, .3, 1);
    }
    return Array.from(positions).length / 2 - initialSize;
}
var init = function() {
    // Canvas element and WebGL context
    const canvas = document.getElementById("glcanvas");
    const gl = canvas.getContext('webgl');
    if (!gl) {
        console.error("No Graphics Library context available. Update or change your browser.");
    }

    // Initialize vertex and fragment shader programs
    const vertexShaderSource = `
    attribute vec4 aVertexPosition;
    attribute vec4 aVertexColor;

    uniform mat4 uModelViewMatrix;
    uniform mat4 uProjectionMatrix;

    varying lowp vec4 vColor;

    void main() {
      gl_Position = uProjectionMatrix * uModelViewMatrix * aVertexPosition;
      vColor = aVertexColor;
    }`;
    const fragmentShaderSource = `
    varying lowp vec4 vColor;

    void main() {
      gl_FragColor = vColor;
    }`;

    const shaderProgram = initShaderProgram(gl, vertexShaderSource, fragmentShaderSource);
    const programInfo = {
        program: shaderProgram,
        attribLocations: {
            vertexPosition: gl.getAttribLocation(shaderProgram, 'aVertexPosition'),
            vertexColor: gl.getAttribLocation(shaderProgram, 'aVertexColor'),
        },
        uniformLocations: {
            projectionMatrix: gl.getUniformLocation(shaderProgram, 'uProjectionMatrix'),
            modelViewMatrix: gl.getUniformLocation(shaderProgram, 'uModelViewMatrix'),
        },
    };

    // Initialize buffers where objects are created
    const buffers = initBuffers(gl);

    // Draw the scene
    drawScene(gl, programInfo, buffers);
}

function initShaderProgram(gl, vertexShaderSource, fragmentShaderSource) {
    // Load shaders
    const vertexShader = loadShader(gl, gl.VERTEX_SHADER, vertexShaderSource);
    const fragmentShader = loadShader(gl, gl.FRAGMENT_SHADER, fragmentShaderSource);

    // Create program
    const shaderProgram = gl.createProgram();
    gl.attachShader(shaderProgram, vertexShader);
    gl.attachShader(shaderProgram, fragmentShader);
    gl.linkProgram(shaderProgram);

    // Check and return
    if (!gl.getProgramParameter(shaderProgram, gl.LINK_STATUS)) {
        console.error("Unable to initialize the shader program.");
        return null;
    }
    return shaderProgram;
}

function loadShader(gl, type, source) {
    const shader = gl.createShader(type);
    gl.shaderSource(shader, source);
    gl.compileShader(shader);
    if (!gl.getShaderParameter(shader, gl.COMPILE_STATUS)) {
        console.error("Shader did not compile.");
        gl.deleteShader(shader);
        return null;
    }
    return shader;
}



function initBuffers(gl) {



    // TODO: update these position and color coordinates.
    let positions = [-3.5, 3.5,
        3.5, 3.5,
        3.5, -3.5, -3.5, -3.5,

    ]; // is a 64bit array

    let colors = [
        1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0,
        1.0, 1.0, 1.0, 1.0,
    ]; // is a 64bit array

    vertexCount = positions.length

    function generateSquare(x, y, color) {
        x0 = x;
        y0 = y;

        x1 = x + 0.5;
        y1 = y;

        x2 = x + 0.5;
        y2 = y - 0.5;

        x3 = x;
        y3 = y - 0.5
        positions.push(x0);
        positions.push(y0);
        positions.push(x1);
        positions.push(y1);
        positions.push(x2);
        positions.push(y2);
        positions.push(x3);
        positions.push(y3);
        colors.push(color[0]);
        colors.push(color[1]);
        colors.push(color[2]);
        colors.push(color[3]);
        colors.push(color[0]);
        colors.push(color[1]);
        colors.push(color[2]);
        colors.push(color[3]);
        colors.push(color[0]);
        colors.push(color[1]);
        colors.push(color[2]);
        colors.push(color[3]);
        colors.push(color[0]);
        colors.push(color[1]);
        colors.push(color[2]);
        colors.push(color[3]);
        squareCount++;
    };


    generateSquare(-2.5, 2, [0.0, 0.0, 0.0, 1.0]);
    generateSquare(-1.5, 2, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(-1.0, 2, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(0, 2, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(2, 2, [0.0, 0.0, 1.0, 1.0]);

    generateSquare(-3.5, 1.5, [0.0, 0.0, 0.0, 1.0]);
    generateSquare(-2.5, 1.5, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(-1.5, 1.5, [0.0, 0.0, 0.0, 1.0]);
    generateSquare(-1, 1.5, [0.0, 0.0, 0.0, 1.0]);
    generateSquare(2.5, 1.5, [0.0, 0.0, 1.0, 1.0]);

    generateSquare(-3.5, 1, [0.0, 0.0, 0.0, 1.0]);
    generateSquare(-3, 1, [0.0, 0.0, 0.0, 1.0]);
    generateSquare(-2.5, 1, [0.0, 0.0, 0.0, 1.0]);
    generateSquare(-2, 1, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(-0.5, 1, [0.0, 0.0, 0.0, 1.0]);
    generateSquare(0, 1, [0.0, 0.0, 0.0, 1.0]);
    generateSquare(0.5, 1, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(1.5, 1, [0.0, 0.0, 0.0, 1.0]);
    generateSquare(2.5, 1, [0.0, 0.0, 1.0, 1.0]);

    generateSquare(-3, 0.5, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(-1.5, 0.5, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(-1, 0.5, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(-0.5, 0.5, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(0.5, 0.5, [0.0, 0.0, .0, 1.0]);
    generateSquare(1, 0.5, [0.0, 0.0, .0, 1.0]);
    generateSquare(1.5, 0.5, [0.0, 0.0, .0, 1.0]);
    generateSquare(3, 0.5, [0.0, 0.0, 1.0, 1.0]);

    generateSquare(-2.5, 0, [0.0, 0.0, 0.0, 1.0]);
    generateSquare(-2, 0, [0.0, 0.0, 0.0, 1.0]);
    generateSquare(-1, 0, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(-0.5, 0, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(0, 0, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(0.5, 0, [0.0, 0.0, .0, 1.0]);
    generateSquare(1.5, 0, [0.0, 0.0, .0, 1.0]);
    generateSquare(2, 0, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(3, 0, [0.0, 0.0, 1.0, 1.0]);

    generateSquare(-3, -0.5, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(-1.5, -0.5, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(-0, -0.5, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(1, -0.5, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(2, -0.5, [0.0, 0.0, 0.0, 1.0]);
    generateSquare(2.5, -0.5, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(3, -0.5, [0.0, 0.0, 0.0, 1.0]);

    generateSquare(-0.5, -1, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(0, -1, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(1.5, -1, [0.0, 0.0, 0.0, 1.0]);
    generateSquare(2.0, -1, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(2.5, -1, [0.0, 0.0, 1.0, 1.0]);

    generateSquare(-3, -1.5, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(-2.5, -1.5, [0.0, 0.0, 0.0, 1.0]);
    generateSquare(-2, -1.5, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(-1.5, -1.5, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(-1, -1.5, [0.0, 0.0, 1.0, 1.0]);

    generateSquare(-0.5, -1.5, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(0, -1.5, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(1.5, -1.5, [0.0, 0.0, 1.0, 1.0]);
    generateSquare(3, -1.5, [0.0, 0.0, 0.0, 1.0]);






    console.log(positions);
    console.log(colors);
    gridOffset = positions.length / 2;
    gridSize = addGrid(positions, colors);
    console.log(gridOffset, gridSize)

    const positionBuffer = gl.createBuffer();
    const colorBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, positionBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(positions), gl.STATIC_DRAW);
    gl.bindBuffer(gl.ARRAY_BUFFER, colorBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(colors), gl.STATIC_DRAW);

    return {
        position: positionBuffer,
        color: colorBuffer,
    }
}

function drawScene(gl, programInfo, buffers) {
    gl.clearColor(0.0, 0.0, 0.0, 1.0); // RGBA
    gl.clearDepth(1.0) // everything
    gl.enable(gl.DEPTH_TEST);
    gl.depthFunc(gl.LEQUAL);

    gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

    const fieldOfView = 45 * Math.PI / 180; // in radians
    const aspect = gl.canvas.clientWidth / gl.canvas.clientHeight;
    const zNear = 0.1;
    const zFar = 100.0;
    const projectionMatrix = mat4.create();

    mat4.perspective(projectionMatrix, fieldOfView, aspect, zNear, zFar);

    const modelViewMatrix = mat4.create();

    mat4.translate(modelViewMatrix, modelViewMatrix, [0, 0, -5.0]);

    {
        const numComponents = 2;
        const type = gl.FLOAT;
        const normalize = false;
        const stride = 0;
        const offset = 0;
        gl.bindBuffer(gl.ARRAY_BUFFER, buffers.position);
        gl.vertexAttribPointer(
            programInfo.attribLocations.vertexPosition,
            numComponents,
            type,
            normalize,
            stride,
            offset);
        gl.enableVertexAttribArray(
            programInfo.attribLocations.vertexPosition);
    }

    {
        const numComponents = 4;
        const type = gl.FLOAT;
        const normalize = false;
        const stride = 0;
        const offset = 0;
        gl.bindBuffer(gl.ARRAY_BUFFER, buffers.color);
        gl.vertexAttribPointer(
            programInfo.attribLocations.vertexColor,
            numComponents,
            type,
            normalize,
            stride,
            offset);
        gl.enableVertexAttribArray(
            programInfo.attribLocations.vertexColor);
    }

    gl.useProgram(programInfo.program);

    gl.uniformMatrix4fv(
        programInfo.uniformLocations.projectionMatrix,
        false,
        projectionMatrix);
    gl.uniformMatrix4fv(
        programInfo.uniformLocations.modelViewMatrix,
        false,
        modelViewMatrix);

    {
        gl.drawArrays(gl.LINES, gridOffset, gridSize); // draws the grid
        // TODO: update vertexCount and first argument of gl.drawArrays().
        offset = 0;
        vertexCount = 4;
        gl.drawArrays(gl.TRIANGLE_FAN, offset, vertexCount); // draws the grid
        for (var i = 1; i < squareCount + 1; i++) {
            gl.drawArrays(gl.TRIANGLE_FAN, i * 4, vertexCount);
        }


    }
}