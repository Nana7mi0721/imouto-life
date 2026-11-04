
undefined4 FUN_0059b3f0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (DAT_00f3a04c == 0) {
    return 0xffffffff;
  }
  if (DAT_00e7984c == param_1) {
    if (DAT_00e39a54 == 0) {
      return 0;
    }
  }
  else if ((DAT_00e39a54 == 0) && (FUN_00568ca0(0), DAT_00dda46c != 0)) {
    FUN_00584d70();
  }
  uVar2 = DAT_00e796c0;
  if (DAT_00e796c0 < 0x10) {
    uVar2 = 0x10;
  }
  if (param_1 == 0) {
    uVar1 = 0;
    if (uVar2 != 0) {
      do {
        if (((&DAT_00e80544)[uVar1] != 1) || (DAT_00e39a54 != 0)) {
          FUN_005d3ad0(uVar1,5,1);
          (&DAT_00e80544)[uVar1] = 1;
        }
        if (((&DAT_00e80584)[uVar1] != 1) || (DAT_00e39a54 != 0)) {
          FUN_005d3ad0(uVar1,6,1);
          (&DAT_00e80584)[uVar1] = 1;
        }
        if (((&DAT_00e805c4)[uVar1] != 1) || (DAT_00e39a54 != 0)) {
          FUN_005d3ad0(uVar1,7,0);
          (&DAT_00e805c4)[uVar1] = 0;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < uVar2);
    }
  }
  else if (param_1 == 1) {
    uVar1 = 0;
    if (uVar2 != 0) {
      do {
        if (((&DAT_00e80544)[uVar1] != 2) || (DAT_00e39a54 != 0)) {
          FUN_005d3ad0(uVar1,5,2);
          (&DAT_00e80544)[uVar1] = 2;
        }
        if (((&DAT_00e80584)[uVar1] != 2) || (DAT_00e39a54 != 0)) {
          FUN_005d3ad0(uVar1,6,2);
          (&DAT_00e80584)[uVar1] = 2;
        }
        if (((&DAT_00e805c4)[uVar1] != 2) || (DAT_00e39a54 != 0)) {
          FUN_005d3ad0(uVar1,7,0);
          (&DAT_00e805c4)[uVar1] = 0;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < uVar2);
    }
  }
  else {
    if (param_1 != 2) {
      return 0xffffffff;
    }
    uVar1 = 0;
    if (uVar2 != 0) {
      do {
        if (((&DAT_00e80544)[uVar1] != 2) || (DAT_00e39a54 != 0)) {
          FUN_005d3ad0(uVar1,5,2);
          (&DAT_00e80544)[uVar1] = 2;
        }
        if (((&DAT_00e80584)[uVar1] != 3) || (DAT_00e39a54 != 0)) {
          FUN_005d3ad0(uVar1,6,3);
          (&DAT_00e80584)[uVar1] = 3;
        }
        if (((&DAT_00e805c4)[uVar1] != 2) || (DAT_00e39a54 != 0)) {
          FUN_005d3ad0(uVar1,7,2);
          (&DAT_00e805c4)[uVar1] = 2;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < uVar2);
    }
  }
  DAT_00e7984c = param_1;
  DAT_00e39a00 = 1;
  return 0;
}

