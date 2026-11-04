
int FUN_00596f70(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = param_1;
  iVar3 = 0;
  if (*param_1 == 0) {
    return -1;
  }
  if (param_1[1] == 1) {
    return 0;
  }
  param_1 = (int *)0x0;
  if (param_3 == 0) {
    return 0;
  }
  do {
    if (piVar1[0x115] == 0) {
      iVar2 = piVar1[2];
      piVar1[0x116] = 0;
      if (iVar2 == 0) {
        iVar2 = FUN_00596d60();
      }
      else if (iVar2 == 1) {
        iVar2 = FUN_005f8eb0(piVar1);
      }
      else if (iVar2 == 2) {
        iVar2 = FUN_005fa400();
      }
      else {
        iVar2 = FUN_005dd2e0();
      }
      if (iVar2 == -1) {
        if (param_3 == 0) {
          return (int)param_1;
        }
        piVar1[1] = 1;
        return (int)param_1;
      }
    }
    iVar2 = param_3;
    if (piVar1[0x115] < param_3) {
      iVar2 = piVar1[0x115];
    }
    FUN_0056d420(param_2 + iVar3,piVar1[0x113] + piVar1[0x116],iVar2);
    piVar1[0x115] = piVar1[0x115] - iVar2;
    piVar1[0x116] = piVar1[0x116] + iVar2;
    piVar1[0x117] = piVar1[0x117] + iVar2;
    param_1 = (int *)((int)param_1 + iVar2);
    param_3 = param_3 - iVar2;
    iVar3 = iVar3 + iVar2;
    if (param_3 == 0) {
      return (int)param_1;
    }
  } while( true );
}

