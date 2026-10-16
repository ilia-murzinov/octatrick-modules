| SYNTH MACHINE -- the machine list's SELECTION GUARD, its limits (2.15). GNU as. Not
| assembled on its own: synth/manifest.py reads this file into machine.s's `remix.inc`
| (after the shared equates), so these three numbers are the only place the limits live.
| Values only: no code, no data.
|
| FM SYNTH and SY DRUM render on the ColdFire; with many tracks of them the unit runs out
| of time and freezes. The machine list (machine.s ml_guard) refuses a choice that would
| take the ACTIVE PART past these limits, counted over its eight audio tracks by the
| signature each machine keeps in the Part. Retune here after a reading of PROCESSOR LOAD
| on the unit; every other line follows (the messages print the numbers below).

        .set    ML_FM_MAX, 1             | FM SYNTH tracks in the Part, at most (VOIC is not limited)
        .set    ML_SY_MAX, 2             | SY DRUM tracks in the Part, at most
        .set    ML_SY_WITH_FM, 1         | SY DRUM tracks in the Part, at most, while an FM SYNTH track is in it
