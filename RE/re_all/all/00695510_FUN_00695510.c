
void FUN_00695510(int *param_1,char param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  piVar2 = param_1;
  if (param_2 == '\0') {
    FUN_00695240(param_1);
  }
  else {
    FUN_006958b0();
  }
  if ((param_1[0x5b] < 1) || (0x10 < param_1[0x5b])) {
    *(undefined4 *)(*param_1 + 0x14) = 7;
    *(int *)(*param_1 + 0x18) = param_1[0x5b];
    *(int *)(*param_1 + 0x1c) = param_1[0x5b];
    (**(code **)*param_1)(param_1);
  }
  iVar3 = param_1[0x5b];
  switch(iVar3) {
  case 2:
    param_1[0x5c] = (int)&DAT_0082309c;
    break;
  case 3:
    param_1[0x5c] = (int)&DAT_00823038;
    break;
  case 4:
    param_1[0x5c] = (int)&DAT_00822fb8;
    break;
  case 5:
    param_1[0x5c] = (int)&DAT_00822f14;
    break;
  case 6:
    param_1[0x5c] = (int)&DAT_00822e44;
    break;
  case 7:
    param_1[0x5c] = (int)&DAT_00822d40;
    break;
  default:
    param_1[0x5c] = (int)&DAT_00822c00;
  }
  if (iVar3 < 8) {
    iVar3 = iVar3 * iVar3 + -1;
  }
  else {
    iVar3 = 0x3f;
  }
  param_1[0x5d] = iVar3;
  if ((((param_1[0x11] == 0) || (param_1[0x10] == 0)) || (param_1[0x13] < 1)) || (param_1[9] < 1)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x21;
    (**(code **)*param_1)(param_1);
  }
  if ((0xffdc < param_1[0x11]) || (0xffdc < param_1[0x10])) {
    *(undefined4 *)(*param_1 + 0x14) = 0x2a;
    *(undefined4 *)(*param_1 + 0x18) = 0xffdc;
    (**(code **)*param_1)(param_1);
  }
  if (param_1[0x12] != 8) {
    *(undefined4 *)(*param_1 + 0x14) = 0x10;
    *(int *)(*param_1 + 0x18) = param_1[0x12];
    (**(code **)*param_1)(param_1);
  }
  if (10 < param_1[0x13]) {
    *(undefined4 *)(*param_1 + 0x14) = 0x1b;
    *(int *)(*param_1 + 0x18) = param_1[0x13];
    *(undefined4 *)(*param_1 + 0x1c) = 10;
    (**(code **)*param_1)(param_1);
  }
  iVar3 = 0;
  param_1[0x40] = 1;
  param_1[0x41] = 1;
  if (0 < param_1[0x13]) {
    piVar6 = (int *)(param_1[0x15] + 0xc);
    do {
      if (((piVar6[-1] < 1) || (4 < piVar6[-1])) || ((*piVar6 < 1 || (4 < *piVar6)))) {
        *(undefined4 *)(*param_1 + 0x14) = 0x13;
        (**(code **)*param_1)(param_1);
      }
      iVar5 = param_1[0x40];
      if (param_1[0x40] <= piVar6[-1]) {
        iVar5 = piVar6[-1];
      }
      param_1[0x40] = iVar5;
      iVar5 = param_1[0x41];
      if (param_1[0x41] <= *piVar6) {
        iVar5 = *piVar6;
      }
      param_1[0x41] = iVar5;
      iVar3 = iVar3 + 1;
      piVar6 = piVar6 + 0x16;
    } while (iVar3 < param_1[0x13]);
  }
  piVar6 = param_1 + 0x13;
  piVar1 = param_1 + 0x15;
  param_1 = (int *)0x0;
  if (0 < *piVar6) {
    piVar6 = (int *)(*piVar1 + 0x24);
    do {
      piVar6[-8] = (int)param_1;
      iVar3 = piVar2[0x42];
      iVar5 = 1;
      iVar4 = iVar3;
      while ((iVar4 <= (int)((-(uint)((char)piVar2[0x35] != '\0') & 4) + 4) &&
             (piVar2[0x40] % (piVar6[-7] * iVar5 * 2) == 0))) {
        iVar5 = iVar5 * 2;
        iVar4 = iVar3 * iVar5;
      }
      *piVar6 = iVar3 * iVar5;
      iVar3 = piVar2[0x43];
      iVar5 = 1;
      iVar4 = iVar3;
      while ((iVar4 <= (int)((-(uint)((char)piVar2[0x35] != '\0') & 4) + 4) &&
             (piVar2[0x41] % (piVar6[-6] * iVar5 * 2) == 0))) {
        iVar5 = iVar5 * 2;
        iVar4 = iVar3 * iVar5;
      }
      iVar3 = iVar3 * iVar5;
      piVar6[1] = iVar3;
      if (iVar3 * 2 < *piVar6) {
        *piVar6 = iVar3 * 2;
      }
      else if (*piVar6 * 2 < piVar6[1]) {
        piVar6[1] = *piVar6 << 1;
      }
      iVar3 = FUN_006848b0(piVar6[-7] * piVar2[0x10],piVar2[0x5b] * piVar2[0x40]);
      piVar6[-2] = iVar3;
      iVar3 = FUN_006848b0(piVar6[-6] * piVar2[0x11],piVar2[0x41] * piVar2[0x5b]);
      piVar6[-1] = iVar3;
      iVar3 = FUN_006848b0(piVar6[-7] * piVar2[0x10] * *piVar6,piVar2[0x5b] * piVar2[0x40]);
      piVar6[2] = iVar3;
      iVar3 = FUN_006848b0(piVar6[1] * piVar6[-6] * piVar2[0x11],piVar2[0x41] * piVar2[0x5b]);
      piVar6[3] = iVar3;
      *(undefined1 *)(piVar6 + 4) = 1;
      param_1 = (int *)((int)param_1 + 1);
      piVar6 = piVar6 + 0x16;
    } while ((int)param_1 < piVar2[0x13]);
  }
  iVar3 = FUN_006848b0(piVar2[0x11],piVar2[0x41] * piVar2[0x5b]);
  piVar2[0x44] = iVar3;
  return;
}

