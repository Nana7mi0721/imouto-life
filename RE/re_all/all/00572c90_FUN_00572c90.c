
uint __thiscall FUN_00572c90(uint param_1,uint *param_2,int param_3,int *param_4,int *param_5)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = FUN_00572ac0(param_3);
  if (iVar2 == 1) {
    if ((byte)*param_2 == 0) {
      if (param_4 == (int *)0x0) {
        return 0;
      }
      *param_4 = 1;
      return 0;
    }
  }
  else if (iVar2 == 2) {
    if ((ushort)*param_2 == 0) {
      if (param_4 != (int *)0x0) {
        *param_4 = 2;
      }
      return 0;
    }
  }
  else if ((iVar2 == 4) && (*param_2 == 0)) {
    if (param_4 != (int *)0x0) {
      *param_4 = 4;
    }
    return 0;
  }
  iVar2 = FUN_00572b40(param_2,param_3);
  if (iVar2 < 0) {
    if (param_4 != (int *)0x0) {
      *param_4 = 0;
    }
    return 0;
  }
  if (param_3 < 0x4e5) {
    if (param_3 == 0x4e4) goto switchD_00572e6b_caseD_1;
    if (param_3 < 0x3b7) {
      if (((param_3 < 0x3b5) && (param_3 != 0x3a4)) && (param_3 != 0x3a8)) {
        return 0;
      }
      if (iVar2 == 2) {
        param_1 = (uint)CONCAT11((byte)*param_2,*(byte *)((int)param_2 + 1));
        *param_5 = *param_5 + 2;
      }
      else {
        param_1 = (uint)(byte)*param_2;
        *param_5 = *param_5 + 1;
      }
      goto LAB_00572f8d;
    }
    if (param_3 < 0x4b0) {
      return 0;
    }
    if (0x4b1 < param_3) {
      return 0;
    }
    if (param_3 == 0x4b1) {
      uVar1 = CONCAT11((byte)*param_2,*(byte *)((int)param_2 + 1));
    }
    else {
      uVar1 = (ushort)*param_2;
    }
    param_1 = (uint)uVar1;
    if (iVar2 == 4) {
      if (param_3 == 0x4b1) {
        uVar1 = CONCAT11(*(byte *)((int)param_2 + 2),*(byte *)((int)param_2 + 3));
      }
      else {
        uVar1 = *(ushort *)((int)param_2 + 2);
      }
      param_1 = ((param_1 & 0x3ff) << 10 | uVar1 & 0x3ff) + 0x10000;
      *param_5 = *param_5 + 2;
      goto LAB_00572f8d;
    }
  }
  else {
    if (0x7fff < param_3) {
      if (param_3 != 0xfde9) {
        return 0;
      }
      switch(iVar2) {
      case 1:
        goto switchD_00572e6b_caseD_1;
      case 2:
        param_1 = ((byte)*param_2 & 0x1f) << 6 | *(byte *)((int)param_2 + 1) & 0x3f;
        *param_5 = *param_5 + 2;
        break;
      case 3:
        param_1 = (((byte)*param_2 & 0xf) << 6 | *(byte *)((int)param_2 + 1) & 0x3f) << 6 |
                  *(byte *)((int)param_2 + 2) & 0x3f;
        *param_5 = *param_5 + 3;
        break;
      case 4:
        param_1 = ((((byte)*param_2 & 7) << 6 | *(byte *)((int)param_2 + 1) & 0x3f) << 6 |
                  *(byte *)((int)param_2 + 2) & 0x3f) << 6 | *(byte *)((int)param_2 + 3) & 0x3f;
        *param_5 = *param_5 + 4;
        break;
      case 5:
        param_1 = (((((byte)*param_2 & 3) << 6 | *(byte *)((int)param_2 + 1) & 0x3f) << 6 |
                   *(byte *)((int)param_2 + 2) & 0x3f) << 6 | *(byte *)((int)param_2 + 3) & 0x3f) <<
                  6 | (byte)param_2[1] & 0x3f;
        *param_5 = *param_5 + 5;
        break;
      case 6:
        param_1 = ((((((byte)*param_2 & 1) << 6 | *(byte *)((int)param_2 + 1) & 0x3f) << 6 |
                    *(byte *)((int)param_2 + 2) & 0x3f) << 6 | *(byte *)((int)param_2 + 3) & 0x3f)
                   << 6 | (byte)param_2[1] & 0x3f) << 6 | *(byte *)((int)param_2 + 5) & 0x3f;
        *param_5 = *param_5 + 6;
        break;
      default:
      }
      goto LAB_00572f8d;
    }
    if (param_3 == 0x7fff) {
      param_1 = CONCAT31(CONCAT21(CONCAT11((byte)*param_2,*(byte *)((int)param_2 + 1)),
                                  *(byte *)((int)param_2 + 2)),*(byte *)((int)param_2 + 3));
      *param_5 = *param_5 + 1;
      goto LAB_00572f8d;
    }
    if (param_3 < 0x7ffc) {
      return 0;
    }
    if (0x7ffd < param_3) {
      if (param_3 != 0x7ffe) {
        return 0;
      }
      param_1 = *param_2;
      *param_5 = *param_5 + 1;
      goto LAB_00572f8d;
    }
switchD_00572e6b_caseD_1:
    param_1 = (uint)(byte)*param_2;
  }
  *param_5 = *param_5 + 1;
LAB_00572f8d:
  if (param_4 != (int *)0x0) {
    *param_4 = iVar2;
  }
  return param_1;
}

