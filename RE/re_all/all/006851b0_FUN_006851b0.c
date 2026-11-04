
void FUN_006851b0(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if ((0xffdc < param_1[8]) || (0xffdc < param_1[7])) {
    *(undefined4 *)(*param_1 + 0x14) = 0x2a;
    *(undefined4 *)(*param_1 + 0x18) = 0xffdc;
    (**(code **)*param_1)(param_1);
  }
  if (param_1[0x30] != 8) {
    *(undefined4 *)(*param_1 + 0x14) = 0x10;
    *(int *)(*param_1 + 0x18) = param_1[0x30];
    (**(code **)*param_1)(param_1);
  }
  if (10 < param_1[9]) {
    *(undefined4 *)(*param_1 + 0x14) = 0x1b;
    *(int *)(*param_1 + 0x18) = param_1[9];
    *(undefined4 *)(*param_1 + 0x1c) = 10;
    (**(code **)*param_1)(param_1);
  }
  iVar2 = 0;
  param_1[0x46] = 1;
  param_1[0x47] = 1;
  if (0 < param_1[9]) {
    piVar3 = (int *)(param_1[0x31] + 0xc);
    do {
      if ((((piVar3[-1] < 1) || (4 < piVar3[-1])) || (*piVar3 < 1)) || (4 < *piVar3)) {
        *(undefined4 *)(*param_1 + 0x14) = 0x13;
        (**(code **)*param_1)(param_1);
      }
      iVar1 = param_1[0x46];
      if (param_1[0x46] <= piVar3[-1]) {
        iVar1 = piVar3[-1];
      }
      param_1[0x46] = iVar1;
      iVar1 = param_1[0x47];
      if (param_1[0x47] <= *piVar3) {
        iVar1 = *piVar3;
      }
      param_1[0x47] = iVar1;
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 0x16;
    } while (iVar2 < param_1[9]);
  }
  if (((char)param_1[0x32] == '\0') &&
     ((*(char *)((int)param_1 + 0xc9) == '\0' || (param_1[0x4c] == 0)))) {
    iVar2 = param_1[0x5f];
    if (iVar2 < 0x51) {
      if (iVar2 != 0x50) {
        switch(iVar2) {
        case 0:
          param_1[0x62] = 1;
          param_1[99] = (int)&DAT_00822c00;
          param_1[100] = 0;
          break;
        default:
          goto switchD_0068530d_caseD_1;
        case 3:
          param_1[0x62] = 2;
          param_1[99] = (int)&DAT_0082309c;
          param_1[100] = 3;
          break;
        case 8:
          param_1[0x62] = 3;
          param_1[99] = (int)&DAT_00823038;
          param_1[100] = 8;
          break;
        case 0xf:
          param_1[0x62] = 4;
          param_1[99] = (int)&DAT_00822fb8;
          param_1[100] = 0xf;
          break;
        case 0x18:
          param_1[0x62] = 5;
          param_1[99] = (int)&DAT_00822f14;
          param_1[100] = 0x18;
          break;
        case 0x23:
          param_1[0x62] = 6;
          param_1[99] = (int)&DAT_00822e44;
          param_1[100] = 0x23;
          break;
        case 0x30:
          param_1[0x62] = 7;
          param_1[99] = (int)&DAT_00822d40;
          param_1[100] = 0x30;
          break;
        case 0x3f:
          goto switchD_0068530d_caseD_3f;
        }
        goto LAB_006854d8;
      }
      param_1[0x62] = 9;
    }
    else {
      switch(iVar2) {
      case 99:
        param_1[0x62] = 10;
        break;
      default:
switchD_0068530d_caseD_1:
        *(undefined4 *)(*param_1 + 0x14) = 0x11;
        *(int *)(*param_1 + 0x18) = param_1[0x5e];
        *(int *)(*param_1 + 0x1c) = param_1[0x5f];
        *(int *)(*param_1 + 0x20) = param_1[0x60];
        *(int *)(*param_1 + 0x24) = param_1[0x61];
        (**(code **)*param_1)(param_1);
        goto LAB_006854d8;
      case 0x78:
        param_1[0x62] = 0xb;
        break;
      case 0x8f:
        param_1[0x62] = 0xc;
        break;
      case 0xa8:
        param_1[0x62] = 0xd;
        break;
      case 0xc3:
        param_1[0x62] = 0xe;
        break;
      case 0xe0:
        param_1[0x62] = 0xf;
        break;
      case 0xff:
        param_1[0x62] = 0x10;
      }
    }
  }
  else {
switchD_0068530d_caseD_3f:
    param_1[0x62] = 8;
  }
  param_1[99] = (int)&DAT_00822c00;
  param_1[100] = 0x3f;
LAB_006854d8:
  iVar2 = 0;
  param_1[0x48] = param_1[0x62];
  param_1[0x49] = param_1[0x62];
  if (0 < param_1[9]) {
    piVar3 = (int *)(param_1[0x31] + 0x28);
    do {
      piVar3[-1] = param_1[0x62];
      *piVar3 = param_1[0x62];
      iVar1 = FUN_006848b0(piVar3[-8] * param_1[7],param_1[0x46] * param_1[0x62]);
      piVar3[-3] = iVar1;
      iVar1 = FUN_006848b0(piVar3[-7] * param_1[8],param_1[0x62] * param_1[0x47]);
      piVar3[-2] = iVar1;
      iVar1 = FUN_006848b0(piVar3[-8] * param_1[7],param_1[0x46]);
      piVar3[1] = iVar1;
      iVar1 = FUN_006848b0(piVar3[-7] * param_1[8],param_1[0x47]);
      piVar3[2] = iVar1;
      *(undefined1 *)(piVar3 + 3) = 1;
      piVar3[10] = 0;
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 0x16;
    } while (iVar2 < param_1[9]);
  }
  iVar2 = FUN_006848b0(param_1[8],param_1[0x47] * param_1[0x62]);
  param_1[0x4a] = iVar2;
  if ((param_1[0x4c] < param_1[9]) || (*(char *)((int)param_1 + 0xc9) != '\0')) {
    *(undefined1 *)(param_1[0x6a] + 0x10) = 1;
    return;
  }
  *(undefined1 *)(param_1[0x6a] + 0x10) = 0;
  return;
}

