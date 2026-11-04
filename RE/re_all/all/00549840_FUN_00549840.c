
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00549840(char *param_1,uint param_2,uint param_3,uint *param_4,uint *param_5,uint *param_6,
            uint *param_7)

{
  byte *pbVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  float *pfVar5;
  float10 fVar6;
  
  pcVar2 = param_1;
  if ((*param_1 != '\0') && (iVar3 = FUN_00546d90(param_1,1), iVar3 < 0)) {
    return 0xffffffff;
  }
  if ((*(uint *)(param_1 + 0x428) <= param_2) || (*(uint *)(param_1 + 0x42c) <= param_3)) {
    return 0xffffffff;
  }
  iVar3 = *(int *)(param_1 + 0x430) * param_3 + *(int *)(param_1 + 0x434);
  if (param_1[3] == '\0') {
    switch(param_1[4]) {
    case '\x01':
      pbVar1 = (byte *)(param_1 + (uint)*(byte *)(iVar3 + param_2) * 4 + 0x28);
      if (param_4 != (uint *)0x0) {
        *param_4 = (uint)pbVar1[2];
      }
      if (param_5 != (uint *)0x0) {
        *param_5 = (uint)pbVar1[1];
      }
      if (param_6 != (uint *)0x0) {
        *param_6 = (uint)*pbVar1;
      }
      if (param_7 == (uint *)0x0) {
        return 0;
      }
      *param_7 = (uint)pbVar1[3];
      return 0;
    case '\x02':
      param_1 = (char *)(uint)*(ushort *)(iVar3 + param_2 * 2);
      break;
    case '\x03':
      param_1 = (char *)(uint)CONCAT12(*(undefined1 *)(param_2 + iVar3 + param_2 * 2 + 2),
                                       *(undefined2 *)(param_2 + iVar3 + param_2 * 2));
      break;
    case '\x04':
      param_1 = *(char **)(iVar3 + param_2 * 4);
      break;
    default:
      return 0xffffffff;
    }
    FUN_00544290(pcVar2,param_1,param_4,param_5,param_6,param_7);
    return 0;
  }
  if (param_1[2] == '\x10') {
    if ((param_1[1] != '\0') && (param_4 != (uint *)0x0)) {
      fVar6 = (float10)FUN_00540830(*(undefined2 *)(iVar3 + param_2 * 8));
      uVar4 = FUN_0050e270((float)(fVar6 * (float10)_DAT_0081ec30));
      *param_4 = uVar4;
    }
    if ((1 < (byte)param_1[1]) && (param_5 != (uint *)0x0)) {
      fVar6 = (float10)FUN_00540830(*(undefined2 *)(iVar3 + 2 + param_2 * 8));
      uVar4 = FUN_0050e270((float)(fVar6 * (float10)_DAT_0081ec30));
      *param_5 = uVar4;
    }
    if ((2 < (byte)param_1[1]) && (param_6 != (uint *)0x0)) {
      fVar6 = (float10)FUN_00540830(*(undefined2 *)(iVar3 + 4 + param_2 * 8));
      uVar4 = FUN_0050e270((float)(fVar6 * (float10)_DAT_0081ec30));
      *param_6 = uVar4;
    }
    if ((3 < (byte)param_1[1]) && (param_7 != (uint *)0x0)) {
      fVar6 = (float10)FUN_00540830(*(undefined2 *)(iVar3 + 6 + param_2 * 8));
      uVar4 = FUN_0050e270((float)(fVar6 * (float10)_DAT_0081ec30));
      *param_7 = uVar4;
      return 0;
    }
  }
  else {
    if (param_1[2] != ' ') {
      return 0xffffffff;
    }
    pfVar5 = (float *)(iVar3 + param_2 * 0x10);
    if ((param_1[1] != '\0') && (param_4 != (uint *)0x0)) {
      uVar4 = FUN_0050e270(*pfVar5 * (float)_DAT_0081ec30);
      *param_4 = uVar4;
    }
    if ((1 < (byte)param_1[1]) && (param_5 != (uint *)0x0)) {
      uVar4 = FUN_0050e270(pfVar5[1] * (float)_DAT_0081ec30);
      *param_5 = uVar4;
    }
    if ((2 < (byte)param_1[1]) && (param_6 != (uint *)0x0)) {
      uVar4 = FUN_0050e270(pfVar5[2] * (float)_DAT_0081ec30);
      *param_6 = uVar4;
    }
    if ((3 < (byte)param_1[1]) && (param_7 != (uint *)0x0)) {
      uVar4 = FUN_0050e270(pfVar5[3] * (float)_DAT_0081ec30);
      *param_7 = uVar4;
    }
  }
  return 0;
}

