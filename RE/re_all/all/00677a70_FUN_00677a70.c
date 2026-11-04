
int FUN_00677a70(int param_1)

{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  byte bVar7;
  int local_14;
  
  uVar3 = *(uint *)(param_1 + 0x104);
  if ((0x7fff < *(uint *)(param_1 + 0x110)) || (0x7fff < uVar3)) {
    return -1;
  }
  if (*(char *)(param_1 + 0x154) == '\0') {
    return (*(uint *)(param_1 + 0x110) + 1) * uVar3;
  }
  piVar1 = (int *)(param_1 + 0x100);
  bVar2 = *(byte *)(param_1 + 0x15a);
  param_1 = 0;
  local_14 = 8;
  uVar4 = 0;
  do {
    if (local_14 < 7) {
      bVar5 = (byte)(local_14 + -1 >> 1);
      bVar7 = (byte)(local_14 + -1 >> 1);
    }
    else {
      bVar5 = 3;
      bVar7 = 3;
    }
    uVar6 = ((1 << (bVar5 & 0x1f)) -
            ((uVar4 & 1) << (3U - (char)((int)(uVar4 + 1) >> 1) & 0x1f) & 7)) + -1 + *piVar1 >>
            (bVar7 & 0x1f);
    if (uVar6 != 0) {
      if (bVar2 < 8) {
        uVar6 = uVar6 * bVar2 + 7 >> 3;
      }
      else {
        uVar6 = (bVar2 >> 3) * uVar6;
      }
      bVar5 = (byte)(local_14 >> 1);
      if (5 < local_14) {
        bVar5 = 3;
      }
      param_1 = param_1 + ((uVar3 - 1) +
                           ((1 << (bVar5 & 0x1f)) -
                           ((~uVar4 & 1) << (3U - (char)((int)uVar4 >> 1) & 0x1f) & 7)) >>
                          (bVar5 & 0x1f)) * (uVar6 + 1);
    }
    local_14 = local_14 + -1;
    uVar4 = uVar4 + 1;
  } while (1 < local_14);
  return param_1;
}

