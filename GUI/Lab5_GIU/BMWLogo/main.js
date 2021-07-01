//3 membri: Perianu Leon, Lenut Razvan, Sas Lorena

//logo BMW


var init = function () {
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
    const positionBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, positionBuffer);

    // TODO: update these position coordinates.
    const stops=100
    const positions = [
    
    ]; 
    for (i = 0; i < stops; i++) {
        positions.push(Math.cos(i * 2 * Math.PI / stops) * 1.3 + 0); // x coord
        positions.push(Math.sin(i * 2 * Math.PI / stops) * 1.3 + 0); // y coord
    }
    for (i = 0; i < stops; i++) {
        positions.push(Math.cos(i * 2 * Math.PI / stops) * 1.3 + 0); // x coord
        positions.push(Math.sin(i * 2 * Math.PI / stops) * 1.3 + 0); // y coord
    }
    for (i = 0; i < stops; i++) {
        positions.push(Math.cos(i * 2 * Math.PI / stops) * 1 + 0); // x coord
        positions.push(Math.sin(i * 2 * Math.PI / stops) * 1 + 0); // y coord
    }
    for (i = 0; i < stops; i++) {
        positions.push(Math.cos(i * 2 * Math.PI / stops) * 1 + 0); // x coord
        positions.push(Math.sin(i * 2 * Math.PI / stops) * 1 + 0); // y coord
    }
    positions.push(0,0,)
    for (i = 25; i < 51; i++) {
        positions.push(Math.cos(i * 2 * Math.PI / stops) * 1 + 0); // x coord
        positions.push(Math.sin(i * 2 * Math.PI / stops) * 1 + 0); // y coord
    }
    positions.push(0,0,)
    for (i = 75; i < 101; i++) {
        positions.push(Math.cos(i * 2 * Math.PI / stops) * 1 + 0); // x coord
        positions.push(Math.sin(i * 2 * Math.PI / stops) * 1 + 0); // y coord
    }
    positions.push(0,0,);
    positions.push(0,1,);
    positions.push(0,0,);
    positions.push(1,0,);
    positions.push(0,0,);
    positions.push(0,-1,);
    positions.push(0,0,);
    positions.push(-1,0,);

    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(positions), gl.STATIC_DRAW);


    const colorBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, colorBuffer);

    // TODO: update these color coordinates.
    const colors = [
    //  RED, GREEN, BLUE, ALPHA,
        // 1.0, 1.0, 1.0, 1.0,  // white
    ]; // is a 64bit array

    for(i=0;i<100;i++)
    {
        colors.push(0.0,0.0,0.0,1.0,);
    }
    for(i=0;i<200;i++)
    {
        colors.push(0.340, 0.337, 0.337,1.0,);
    }
    for(i=0;i<100;i++)
    {
        colors.push(1.0,1.0,1.0,1.0,);
    }
    for(i=0;i<55;i++)
    {
        colors.push(0.0,0.0,1.0,1.0,);
    }
    for(i=0;i<4;i++)
    {
        colors.push(0.340, 0.337, 0.337,1.0,)
    }

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

    const fieldOfView = 45 * Math.PI / 180;   // in radians
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
        // const offset = 0;
        // TODO: update vertexCount and first argument of gl.drawArrays().
        // const vertexCount = 8;
        gl.drawArrays(gl.TRIANGLE_FAN, 0, 100);
        gl.drawArrays(gl.TRIANGLE_FAN, 300, 100);
        gl.drawArrays(gl.TRIANGLE_FAN, 400,27);
        gl.drawArrays(gl.TRIANGLE_FAN, 427,27);
        gl.drawArrays(gl.LINE_LOOP, 100, 100);
        gl.drawArrays(gl.LINE_LOOP, 200, 100);
        gl.drawArrays(gl.LINES, 454, 8);

        
    }
}