console.clear();
var scene = new THREE.Scene();
var camera = new THREE.PerspectiveCamera(-95,
    16 / 9,
    0.1,
    1000
);
camera.position.set(30, 30, -35);
var renderer = new THREE.WebGLRenderer({ antialias: true });
renderer.setSize(window.innerWidth, window.innerHeight);
renderer.setClearColor(0x333333);
document.body.appendChild(renderer.domElement);

var controls = new THREE.OrbitControls(camera, renderer.domElement);
controls.target.set(30, 30, 0, );
controls.update();
var light = new THREE.DirectionalLight(0xffffff, 0.5);
light.position.setScalar(10);
scene.add(light);
scene.add(new THREE.AmbientLight(0xffffff, 0.5));

var uLogoGeom = new THREE.BufferGeometry();
uLogoGeom.addAttribute('position', new THREE.BufferAttribute(new Float32Array(uLogoPoints), 3));
var uLogo = new THREE.LineSegments(
    uLogoGeom,
    new THREE.LineDashedMaterial({
        color: 0xff0000,
        scale: 100,
    }),

);
uLogo.computeLineDistances();
var logoLength =
    uLogoGeom.attributes.lineDistance.array[
        uLogoGeom.attributes.lineDistance.count - 1
    ];
uLogo.material.dashSize = 0;
uLogo.material.gapSize = 1000;

uLogo.scale.setScalar(0.1);
scene.add(uLogo);

// var loader = new THREE.OBJLoader();
// loader.load('/logo-GIU.glb', u => {
//   u.children[0].geometry.computeVertexNormals();
//   u.children[0].material = new THREE.MeshStandardMaterial({
//     color: 0xff9900,
//     metalness: 0.75,
//     roughness: 0.55
//   });
//   u.rotation.y = Math.PI;
//   u.visible = false;
//   uLogo.add(u);
// });

var clock = new THREE.Clock();
var time = 0;
var delta = 0;
var speed = 40000;
var dash = 0;
var aSpeed = THREE.Math.degToRad(20);

render();

function render() {
    requestAnimationFrame(render);
    delta = clock.getDelta();
    time += delta;
    dash = speed * time;
    uLogo.material.dashSize = dash;
    if (dash > logoLength) {
        if (!uLogo.children[0].visible) {
            uLogo.material.color.set("yellow");
            uLogo.children[0].visible = true;
        }
        uLogo.material.dashSize = logoLength;
        uLogo.rotation.y += aSpeed * delta;
    }
    renderer.render(scene, camera);
}