package com.example.learnopengl;

import androidx.appcompat.app.AppCompatActivity;

import android.opengl.GLES20;
import android.opengl.GLES32;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.example.learnopengl.databinding.ActivityMainBinding;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'learnopengl' library on application startup.

    public final String TAG = "OpenGL2024";
    static {
        System.loadLibrary("learnopengl");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

//        binding = ActivityMainBinding.inflate(getLayoutInflater());
//        setContentView(binding.getRoot());
//
//        // Example of a call to a native method
//        TextView tv = binding.sampleText;
//        tv.setText(stringFromJNI());

        GLSurfaceView glSurfaceView = new GLSurfaceView(this);
        glSurfaceView.setEGLContextClientVersion(2);

        setContentView(glSurfaceView);

        glSurfaceView.setRenderer(new GLSurfaceView.Renderer() {

            private Triangle mTriangle;

            @Override
            public void onSurfaceCreated(GL10 gl, EGLConfig config) {
                gl.glClearColor(1.0f,1.0f,1.0f,0.0f);

            }

            @Override
            public void onSurfaceChanged(GL10 gl, int width, int height) {
                Log.e(TAG,"width: "+width+" height: "+height);
                gl.glViewport(0,0,width,height);
                //mTriangle = new Triangle();
                initTriangle();
            }

            @Override
            public void onDrawFrame(GL10 gl) {
                gl.glClear(GLES32.GL_COLOR_BUFFER_BIT);
                //mTriangle.draw();
                //drawTriangle();
                drawRectangle();
            }
        });

    }

    /**
     * A native method that is implemented by the 'learnopengl' native library,
     * which is packaged with this application.
     */
    public native void initTriangle();
    public native void drawTriangle();

    public native void drawRectangle();
}