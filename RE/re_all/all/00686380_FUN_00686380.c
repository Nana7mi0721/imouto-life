
void FUN_00686380(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iStack_4;
  
  if (param_1[5] != 0xca) {
    *(undefined4 *)(*param_1 + 0x14) = 0x15;
    *(int *)(*param_1 + 0x18) = param_1[5];
    (**(code **)*param_1)(param_1);
  }
  FUN_00684960(param_1);
  iStack_4 = 0;
  if (0 < param_1[9]) {
    piVar3 = (int *)(param_1[0x31] + 0x24);
    do {
      iVar5 = param_1[0x48];
      iVar4 = 1;
      iVar2 = iVar5;
      while ((iVar2 <= (int)((-(uint)((char)param_1[0x12] != '\0') & 4) + 4) &&
             (param_1[0x46] % (piVar3[-7] * iVar4 * 2) == 0))) {
        iVar4 = iVar4 * 2;
        iVar2 = iVar5 * iVar4;
      }
      *piVar3 = iVar5 * iVar4;
      iVar5 = param_1[0x49];
      iVar4 = 1;
      iVar2 = iVar5;
      while ((iVar2 <= (int)((-(uint)((char)param_1[0x12] != '\0') & 4) + 4) &&
             (param_1[0x47] % (piVar3[-6] * iVar4 * 2) == 0))) {
        iVar4 = iVar4 * 2;
        iVar2 = iVar5 * iVar4;
      }
      iVar5 = iVar5 * iVar4;
      piVar3[1] = iVar5;
      if (iVar5 * 2 < *piVar3) {
        *piVar3 = iVar5 * 2;
      }
      else if (*piVar3 * 2 < piVar3[1]) {
        piVar3[1] = *piVar3 << 1;
      }
      iStack_4 = iStack_4 + 1;
      piVar3 = piVar3 + 0x16;
    } while (iStack_4 < param_1[9]);
  }
  iVar5 = 0;
  if (0 < param_1[9]) {
    piVar3 = (int *)(param_1[0x31] + 8);
    do {
      iVar4 = FUN_006848b0(piVar3[7] * *piVar3 * param_1[7],param_1[0x62] * param_1[0x46]);
      piVar3[9] = iVar4;
      iVar4 = FUN_006848b0(piVar3[8] * piVar3[1] * param_1[8],param_1[0x62] * param_1[0x47]);
      piVar3[10] = iVar4;
      iVar5 = iVar5 + 1;
      piVar3 = piVar3 + 0x16;
    } while (iVar5 < param_1[9]);
  }
  switch(param_1[0xb]) {
  case 1:
    param_1[0x19] = 1;
    break;
  case 2:
  case 3:
    param_1[0x19] = 3;
    break;
  case 4:
  case 5:
    param_1[0x19] = 4;
    break;
  default:
    param_1[0x19] = param_1[9];
  }
  iVar5 = 1;
  if (*(char *)((int)param_1 + 0x4a) == '\0') {
    iVar5 = param_1[0x19];
  }
  param_1[0x1a] = iVar5;
  cVar1 = FUN_00686580(param_1);
  if (cVar1 == '\0') {
    param_1[0x1b] = 1;
    return;
  }
  param_1[0x1b] = param_1[0x47];
  return;
}

