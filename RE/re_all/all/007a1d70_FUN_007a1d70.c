
undefined4 FUN_007a1d70(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  if (param_2 < 0x2719) {
    if (param_2 == 0x2718) {
      if ((0 < (int)param_3) && ((int)param_3 < 3)) {
        param_1[3] = (int)param_3;
        return 0;
      }
    }
    else if (param_2 < 0xfc0) {
      if (param_2 == 0xfbf) {
        if (param_3 != (int *)0x0) {
          *param_3 = param_1[9];
          return 0;
        }
      }
      else {
        if (param_2 != 0xfbb) {
          if (param_2 != 0xfbc) {
            return 0xfffffffb;
          }
          iVar4 = *param_1;
          iVar1 = *(int *)(iVar4 + 8);
          piVar2 = param_1 + (param_1[1] + 0x818) * param_1[2] + iVar1 * 2 + 0x15;
          piVar5 = param_1 + 9;
          for (uVar3 = ((*(int *)(iVar4 + 4) + 0x818) * param_1[2] + *(int *)(iVar4 + 8) * 8) * 4 +
                       0x30U >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *piVar5 = 0;
            piVar5 = piVar5 + 1;
          }
          for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
            *(undefined1 *)piVar5 = 0;
            piVar5 = (int *)((int)piVar5 + 1);
          }
          iVar4 = 0;
          if (*(int *)(*param_1 + 8) << 1 < 1) {
            return 0;
          }
          do {
            piVar2[iVar1 * 2] = -0x3e200000;
            *piVar2 = -0x3e200000;
            iVar4 = iVar4 + 1;
            piVar2 = piVar2 + 1;
          } while (iVar4 < *(int *)(*param_1 + 8) * 2);
          return 0;
        }
        if (param_3 != (int *)0x0) {
          *param_3 = param_1[1] / param_1[4];
          return 0;
        }
      }
    }
    else if (param_2 == 0xfc1) {
      if (param_3 != (int *)0x0) {
        *param_3 = param_1[0xd];
        return 0;
      }
    }
    else {
      if (param_2 != 0x2717) {
        return 0xfffffffb;
      }
      if (param_3 != (int *)0x0) {
        *param_3 = param_1[10];
        param_1[10] = 0;
        return 0;
      }
    }
  }
  else {
    switch(param_2) {
    case 0x271a:
      if ((-1 < (int)param_3) && ((int)param_3 < *(int *)(*param_1 + 8))) {
        param_1[5] = (int)param_3;
        return 0;
      }
      break;
    default:
      return 0xfffffffb;
    case 0x271c:
      if ((0 < (int)param_3) && ((int)param_3 <= *(int *)(*param_1 + 8))) {
        param_1[6] = (int)param_3;
        return 0;
      }
      break;
    case 0x271f:
      if (param_3 != (int *)0x0) {
        *param_3 = *param_1;
        return 0;
      }
      break;
    case 0x2720:
      param_1[7] = (int)param_3;
      return 0;
    }
  }
  return 0xffffffff;
}

