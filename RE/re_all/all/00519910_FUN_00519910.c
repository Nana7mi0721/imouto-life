
void FUN_00519910(int param_1)

{
  if ((DAT_00a38288 != 1) && (DAT_00a37d78 != 0)) {
    if ((DAT_00a3828c == 0) && (param_1 == 0)) {
      FUN_00567d00(&DAT_00a38310);
      DAT_00a3828c = 1;
    }
    if (DAT_00a38350 == 0) {
      FUN_00567d20(&DAT_00a383d8);
      DAT_00a38350 = 1;
    }
    if (DAT_00a38418 == 0) {
      FUN_00568ca0(0);
      if (DAT_00dda46c != 0) {
        FUN_00584d70();
      }
      DAT_00a381c4 = 0;
      DAT_00a38418 = 1;
      FUN_00567c10(&DAT_00a384a0);
    }
    if (DAT_00a38d34 == 0) {
      FUN_00567c30(DAT_00a38d30,&DAT_00a38d38,0xffffffff);
      DAT_00a38d34 = 1;
    }
    DAT_00a38288 = (uint)(DAT_00a3828c == 1);
  }
  return;
}

