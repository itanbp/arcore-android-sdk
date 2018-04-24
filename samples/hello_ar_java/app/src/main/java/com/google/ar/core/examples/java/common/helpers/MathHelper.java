package com.google.ar.core.examples.java.common.helpers;

import com.google.ar.core.Pose;

import java.util.Arrays;

/**
 * Created by itanbp on 24/04/2018.
 */

public class MathHelper {

    /**
     * Returns a pose rotating about the origin so that the point {@code from} is rotated to be
     * colinear with the origin and {@code to}.  Rotation takes the shortest path.
     */
    public static Pose rotateBetween(float[] fromRaw, float[] toRaw) {
        float[] from = Arrays.copyOf(fromRaw, 3);
        normalize(from);
        float[] to = Arrays.copyOf(toRaw, 3);
        normalize(to);

        float[] cross = new float[3];
        cross[0] = from[1] * to[2] - from[2] * to[1];
        cross[1] = from[2] * to[0] - from[0] * to[2];
        cross[2] = from[0] * to[1] - from[1] * to[0];
        float dot = from[0] * to[0] + from[1] * to[1] + from[2] * to[2];
        float angle = (float) Math.atan2(norm(cross), dot);
        normalize(cross);

        float sinhalf = (float) Math.sin(angle / 2.0f);
        float coshalf = (float) Math.cos(angle / 2.0f);

        return Pose.makeRotation(cross[0] * sinhalf, cross[1] * sinhalf, cross[2] * sinhalf, coshalf);
    }

    /**
     * Normalizes the input array in-place.
     */
    public static void normalize(float[] in) {
        float scale = 1 / norm(in);
        for (int i = 0; i < in.length; ++i) {
            in[i] *= scale;
        }
    }

    /**
     * Returns the 2-norm of the input array.
     */
    public static float norm(float[] in) {
        float sum = 0;
        for (float f : in) {
            sum += f * f;
        }
        return (float) Math.sqrt(sum);
    }


    public static float[] getPoseTranslation(Pose p) {
        float[] out = new float[3];
        p.getTranslation(out, 0);
        return out;
    }

}
