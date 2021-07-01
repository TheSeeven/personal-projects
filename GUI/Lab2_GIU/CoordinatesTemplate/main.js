var coordsSize;
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

    uniform mat4 uModelViewMatrix;
    uniform mat4 uProjectionMatrix;

    void main() {
      gl_Position = uProjectionMatrix * uModelViewMatrix * aVertexPosition;
    }`;
    const fragmentShaderSource = `
    void main() {
      gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
    }`;

    const shaderProgram = initShaderProgram(gl, vertexShaderSource, fragmentShaderSource);
    const programInfo = {
        program: shaderProgram,
        attribLocations: {
            vertexPosition: gl.getAttribLocation(shaderProgram, 'aVertexPosition'),
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

    // TODO: update these coordinates.
    const positions = [
    //  x, y,
       
        // litera E
        
        -1, 1,
        1, 1,

        -1, 1,
        -1, -3,

        -1, -3,
        1, -3,
        
        1, -3,
        1, -2.5,

        1, -2.5,
        -0.5, -2.5,
        
        -0.5, -2.5,
        -0.5, -1.25,

        -0.5, -1.25,
        1, -1.25,

        1, -1.25,
        1, -0.75,

        1, -0.75,
        -0.5, -0.75,

        -0.5, -0.75,
        -0.5, 0.5,
        
        -0.5, 0.5,
        1, 0.5,
        
        1, 0.5,
        1, 1,
        
        // litera Y

        -5, -3,
        -4.3, -3,

        -4.3, -3,
        -4.3, -1,
        
        -4.3, -1,
        -3, 1,

        -3, 1,
        -3.5, 1,

        -3.5, 1,
        -4.65, -0.6,
        
        -4.65, -0.6,
        -5.5, 1,

        -5.5, 1,
        -6, 1,
        
        -6, 1,
        -5, -1,
        
        -5, -1,
        -5, -3,

        // litera P

        3, -3,
        3, 1,

        3, 1,
        5, 1,

        5, 1,
        5, -1,

        5, -1,
        3.5, -1,
        
        3.5, -1,
        3.5, -3,
        
        3.5, -3,
        3, -3,

        3.5, 0.5,
        4.5, 0.5,

        4.5, 0.5,
        4.5, -0.5,

        4.5, -0.5,
        3.5, -0.5,
        
        3.5, -0.5,
        3.5, 0.5,

    ] // is a 64bit array

    coordsSize = positions.length;
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(positions), gl.STATIC_DRAW);

    return {
        position: positionBuffer,
    }
}

function drawScene(gl, programInfo, buffers) {
    gl.clearColor(0.0, 0.0, 0.0, 1.0); // RGBA
    gl.clearDepth(1.0) // everything
    gl.enable(gl.DEPTH_TEST);
    gl.depthFunc(gl.LEQUAL);

    gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

    const fieldOfView = 75 * Math.PI / 180;   // in radians
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
        const offset = 0;
        // TODO: update vertexCount and first argument of gl.drawArrays().
        const vertexCount = coordsSize;
        gl.drawArrays(gl.LINES, offset, vertexCount);
    }
}