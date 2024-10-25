<h1>Rotating Cube</h1>

This OpenGL project demonstrates how to create a rotating 3D cube with colorful faces using C++. Each face of the cube is randomly colored, adding a dynamic visual effect as it rotates along the x, y, and z axes. This program utilizes basic OpenGL and GLUT functions to initialize a display window, handle 3D rendering, and manage viewport resizing. Through this project, I learnt foundational concepts of 3D graphics in OpenGL, including setting up a rendering window, applying transformations, and handling animations with simple rotation.

<img src ="ss.png" width="60%">

<h3>Prerequisites</h3>
    <ol>
        <li>
            <p><strong>C++ Compiler</strong>: Make sure you have a C++ compiler installed. GCC is common for Linux and
                macOS; Visual Studio is popular for Windows.</p>
        </li>
        <li>
            <p><strong>OpenGL and GLUT Libraries</strong>: Install OpenGL and GLUT to render graphics in C++.</p>
            <ul>
                <li>
                    <p><strong>Linux</strong>: Install OpenGL and GLUT using:</p>
                    <pre class="!overflow-visible"><div class="contain-inline-size rounded-md border-[0.5px] border-token-border-medium relative bg-token-sidebar-surface-primary dark:bg-gray-950"><div class="flex items-center text-token-text-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md h-9 bg-token-sidebar-surface-primary dark:bg-token-main-surface-secondary">bash</div><div class="sticky top-9 md:top-[5.75rem]"><div class="absolute bottom-0 right-2 flex h-9 items-center"><div class="flex items-center rounded bg-token-sidebar-surface-primary px-2 font-sans text-xs text-token-text-secondary dark:bg-token-main-surface-secondary"><span class="" data-state="closed"></span></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-bash">sudo apt update
sudo apt install freeglut3-dev
</code></div></div></pre>
                </li>
                <li>
                    <p><strong>macOS</strong>: Install OpenGL using <a rel="noopener" target="_new"
                            href="https://brew.sh/"
                            style="--streaming-animation-state: var(--batch-play-state-1); --animation-rate: var(--batch-play-rate-1);"><span
                                style="--animation-count: 0; --streaming-animation-state: var(--batch-play-state-2);">Homebrew</span></a>:
                    </p>
                    <pre class="!overflow-visible"><div class="contain-inline-size rounded-md border-[0.5px] border-token-border-medium relative bg-token-sidebar-surface-primary dark:bg-gray-950"><div class="flex items-center text-token-text-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md h-9 bg-token-sidebar-surface-primary dark:bg-token-main-surface-secondary">bash</div><div class="sticky top-9 md:top-[5.75rem]"><div class="absolute bottom-0 right-2 flex h-9 items-center"><div class="flex items-center rounded bg-token-sidebar-surface-primary px-2 font-sans text-xs text-token-text-secondary dark:bg-token-main-surface-secondary"><span class="" data-state="closed"></span></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-bash">brew install freeglut
</code></div></div></pre>
                </li>
                <li>
                    <p><strong>Windows</strong>: Install <a rel="noopener" target="_new"
                            style="--streaming-animation-state: var(--batch-play-state-1); --animation-rate: var(--batch-play-rate-1);"><span
                                style="--animation-count: 2; --streaming-animation-state: var(--batch-play-state-2);">freeglut</span></a>
                        and ensure your project’s linker settings include <code>opengl32.lib</code>,
                        <code>glu32.lib</code>, and <code>glut32.lib</code>.</p>
                </li>
            </ul>
        </li>
    </ol>
    <h3>Step 1: Understanding the Program</h3>
    <p>The program initializes a window and displays a rotating 3D cube, where each face has a random color. The
        rotation occurs along the x, y, and z axes. Here’s a breakdown of the key components:</p>
    <ul>
        <li><strong>Color Array</strong>: Stores randomized colors for each cube face.</li>
        <li><strong>Rotation Angle</strong>: Controls the rotation speed and angle.</li>
        <li><strong>Functions</strong>:<ul>
                <li><code>initializeOpenGL</code>: Sets up the OpenGL environment and creates the display window.</li>
                <li><code>updateColorArray</code>: Generates random colors for the cube’s faces.</li>
                <li><code>drawFace</code>: Draws a single face of the cube.</li>
                <li><code>drawCube</code>: Calls <code>drawFace</code> for each of the cube’s six faces.</li>
                <li><code>rotateCube</code>: Increments the rotation angle to keep the cube rotating.</li>
                <li><code>onDisplay</code>: Clears the screen and renders the cube each frame.</li>
                <li><code>onReshape</code>: Adjusts the viewport if the window size changes.</li>
            </ul>
        </li>
    </ul>
    <h3>Step 2: Setting Up the Code</h3>
    <ol>
        <li>
            <p><strong>Create a New Project/Directory</strong>:</p>
            <ul>
                <li>Open your IDE or text editor.</li>
                <li>Create a new file named <code>OpenGLCube.cpp</code> and paste in the refactored code.</li>
            </ul>
        </li>
        <li>
            <p><strong>Code Structure</strong>:
                Make sure the code includes the <code>GL/glut.h</code> library, which is necessary for rendering in
                OpenGL.</p>
        </li>
    </ol>
    <h3>Step 3: Compiling the Program</h3>
    <p>Open a terminal (or command prompt on Windows) and navigate to the directory where <code>OpenGLCube.cpp</code> is
        located. Compile the code as follows:</p>
    <ul>
        <li>
            <p><strong>Linux/macOS</strong>:</p>
            <pre class="!overflow-visible"><div class="contain-inline-size rounded-md border-[0.5px] border-token-border-medium relative bg-token-sidebar-surface-primary dark:bg-gray-950"><div class="flex items-center text-token-text-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md h-9 bg-token-sidebar-surface-primary dark:bg-token-main-surface-secondary">bash</div><div class="sticky top-9 md:top-[5.75rem]"><div class="absolute bottom-0 right-2 flex h-9 items-center"><div class="flex items-center rounded bg-token-sidebar-surface-primary px-2 font-sans text-xs text-token-text-secondary dark:bg-token-main-surface-secondary"><span class="" data-state="closed"></span></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-bash">g++ OpenGLCube.cpp -o OpenGLCube -lGL -lGLU -lglut
</code></div></div></pre>
        </li>
        <li>
            <p><strong>Windows</strong> (Visual Studio Command Prompt):</p>
            <pre class="!overflow-visible"><div class="contain-inline-size rounded-md border-[0.5px] border-token-border-medium relative bg-token-sidebar-surface-primary dark:bg-gray-950"><div class="flex items-center text-token-text-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md h-9 bg-token-sidebar-surface-primary dark:bg-token-main-surface-secondary">cmd</div><div class="sticky top-9 md:top-[5.75rem]"><div class="absolute bottom-0 right-2 flex h-9 items-center"><div class="flex items-center rounded bg-token-sidebar-surface-primary px-2 font-sans text-xs text-token-text-secondary dark:bg-token-main-surface-secondary"><span class="" data-state="closed"></span></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cmd">g++ OpenGLCube.cpp -o OpenGLCube -lopengl32 -lglu32 -lfreeglut
</code></div></div></pre>
        </li>
    </ul>
    <h3>Step 4: Running the Program</h3>
    <p>After successful compilation, run the executable:</p>
    <pre class="!overflow-visible"><div class="contain-inline-size rounded-md border-[0.5px] border-token-border-medium relative bg-token-sidebar-surface-primary dark:bg-gray-950"><div class="flex items-center text-token-text-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md h-9 bg-token-sidebar-surface-primary dark:bg-token-main-surface-secondary">bash</div><div class="sticky top-9 md:top-[5.75rem]"><div class="absolute bottom-0 right-2 flex h-9 items-center"><div class="flex items-center rounded bg-token-sidebar-surface-primary px-2 font-sans text-xs text-token-text-secondary dark:bg-token-main-surface-secondary"><span class="" data-state="closed"></span></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-bash">./OpenGLCube    <span class="hljs-comment"># On Linux/macOS</span>
OpenGLCube.exe  <span class="hljs-comment"># On Windows</span>
</code></div></div></pre>
    <h3>Step 5: Exploring Program Behavior</h3>
    <ul>
        <li><strong>Rotation</strong>: The cube should automatically start rotating. The rotation speed and angle are
            controlled by the <code>rotateCube()</code> function.</li>
        <li><strong>Randomized Colors</strong>: Each face of the cube has a unique color, which is generated randomly at
            the start by <code>updateColorArray()</code>.</li>
        <li><strong>Interaction</strong>: Resize the window to see <code>onReshape()</code> adjust the viewport, keeping
            the cube’s proportions intact.</li>
    </ul>
    <h3>Step 6: Experimenting with the Program</h3>
    <ol>
        <li>
            <p><strong>Change Rotation Speed</strong>: In the <code>rotateCube()</code> function, modify the rotation
                speed by adjusting <code>rotationAngle += 0.3f;</code>.</p>
        </li>
        <li>
            <p><strong>Adjust Cube Colors</strong>: Customize the cube colors by modifying the
                <code>updateColorArray()</code> function. You could set specific colors rather than random ones if
                desired.</p>
        </li>
        <li>
            <p><strong>Window Properties</strong>: Change the initial window size and position in
                <code>initializeOpenGL()</code> by adjusting <code>INITIAL_WIN_WIDTH</code>,
                <code>INITIAL_WIN_HEIGHT</code>, and the window position coordinates in
                <code>glutInitWindowSize()</code> and <code>glutInitWindowPosition()</code>.</p>
        </li>
    </ol>
    <h3>Troubleshooting</h3>
    <ul>
        <li><strong>Missing Library Errors</strong>: If you encounter issues with missing OpenGL or GLUT libraries,
            verify your installation, or check your linker settings.</li>
        <li><strong>Black or White Screen</strong>: If the cube isn’t showing, ensure
            <code>glEnable(GL_DEPTH_TEST);</code> is called, as this is required for correct 3D rendering in OpenGL.
        </li>
    </ul>
    