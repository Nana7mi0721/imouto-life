
undefined4 FUN_0055bda0(int *param_1,int param_2,int param_3,int param_4,uint param_5,int param_6)

{
  int *piVar1;
  uint in_EAX;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  piVar4 = (int *)0x0;
  iVar2 = FUN_0057e0e0();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if (param_6 == 0) {
    if (DAT_00cc4db0 == 0) {
      return 0xffffffff;
    }
    if ((int)param_5 < 0) {
      return 0xffffffff;
    }
    if ((param_5 & 0x7c000000) != DAT_00cc4dd8) {
      return 0xffffffff;
    }
    if (DAT_00cc4de0 <= (int)(param_5 & 0xffff)) {
      return 0xffffffff;
    }
    piVar5 = *(int **)(DAT_00cc4db4 + (param_5 & 0xffff) * 4);
    if (piVar5 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar5 * 0x10000 != (param_5 & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (piVar5[4] != 0) {
      return 0xffffffff;
    }
  }
  else {
    if (DAT_00cc4db0 == 0) {
      return 0xffffffff;
    }
    if ((int)param_5 < 0) {
      return 0xffffffff;
    }
    if ((param_5 & 0x7c000000) != DAT_00cc4dd8) {
      return 0xffffffff;
    }
    if (DAT_00cc4de0 <= (int)(param_5 & 0xffff)) {
      return 0xffffffff;
    }
    piVar5 = *(int **)(DAT_00cc4db4 + (param_5 & 0xffff) * 4);
    if (piVar5 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar5 * 0x10000 != (param_5 & 0x3ff0000)) {
      return 0xffffffff;
    }
  }
  if (in_EAX != 0xffffffff) {
    if ((int)in_EAX < 0) {
      return 0xffffffff;
    }
    if ((in_EAX & 0x7c000000) != DAT_00cc4dd8) {
      return 0xffffffff;
    }
    if (DAT_00cc4de0 <= (int)(in_EAX & 0xffff)) {
      return 0xffffffff;
    }
    piVar4 = *(int **)(DAT_00cc4db4 + (in_EAX & 0xffff) * 4);
    if (piVar4 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar4 * 0x10000 != (in_EAX & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (piVar4[4] != 0) {
      return 0xffffffff;
    }
    if (param_3 != 0) {
      return 0xffffffff;
    }
    param_2 = piVar4[0x93e];
    param_1 = piVar4 + 0x47d;
  }
  if (param_3 == 0) {
    iVar2 = 0;
    if (0 < param_4) {
      do {
        if (iVar2 == 0) {
          if (piVar4 != (int *)0x0) goto LAB_0055bf64;
LAB_0055bfc3:
          iVar3 = FUN_005514a0(piVar5 + iVar2 * 0x6e + 0x31,param_2,param_1,0,1,0,piVar5[0x10]);
          if (iVar3 != 0) {
            if (iVar2 + -1 != -1) {
              piVar5 = piVar5 + (iVar2 + -1) * 0x6e + 0x31;
              do {
                if (*piVar5 != 0) {
                  FUN_005517a0(piVar5);
                }
                piVar5 = piVar5 + -0x6e;
                iVar2 = iVar2 + -1;
              } while (iVar2 != 0);
            }
            FUN_0056bb10(&PTR_LAB_007d63c0);
            return 0xffffffff;
          }
          piVar5[iVar2 + 0x941] = 0;
        }
        else {
          if (piVar4 == (int *)0x0) {
            iVar3 = piVar5[0x10];
            piVar1 = piVar5;
          }
          else {
LAB_0055bf64:
            iVar3 = piVar5[0x10];
            piVar1 = piVar4;
          }
          iVar3 = FUN_00551770(piVar5 + iVar2 * 0x6e + 0x31,piVar1 + 0x31,iVar3);
          piVar5[iVar2 + 0x941] = 0;
          if (iVar3 != 0) {
            if ((piVar4 != (int *)0x0) && (iVar2 == 0)) goto LAB_0055bfc3;
            param_4 = iVar2;
            break;
          }
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_4);
    }
    piVar5[0x1c] = param_4;
  }
  else if (param_3 == 1) {
    iVar2 = FUN_005514a0(piVar5 + 0x31,param_2,param_1,0,1,1,piVar5[0x10]);
    if (iVar2 != 0) {
      FUN_0056bb10(&DAT_007d63fc);
      return 0xffffffff;
    }
    piVar5[0x1c] = 1;
  }
  piVar5[0x482] = param_3;
  if (param_3 == 1) {
    FUN_0056da60(&DAT_00a837b0,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x2ee);
    FUN_005807e0(&DAT_00a83790,piVar5 + 0x93a,param_5,piVar5);
    FUN_0056dac0(&DAT_00a837b0);
  }
  return 0;
}

