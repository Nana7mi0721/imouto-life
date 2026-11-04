
undefined4
FUN_00544640(undefined1 *param_1,int param_2,uint param_3,uint param_4,uint param_5,uint param_6,
            int param_7,int param_8,undefined1 param_9)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  
  FUN_0056d380(param_1,0,0x428);
  *param_1 = 0;
  if ((param_7 != 0) && (param_8 != 0)) {
    param_1[1] = (char)param_7;
    param_1[3] = param_9;
    param_1[4] = (char)((int)(param_7 * param_8 + (param_7 * param_8 >> 0x1f & 7U)) >> 3);
    param_1[2] = (char)param_8;
    return 0;
  }
  param_1[4] = (char)((int)(param_2 + (param_2 >> 0x1f & 7U)) >> 3);
  *(uint *)(param_1 + 0x18) = param_5;
  param_1[2] = 0;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[5] = (byte)param_2;
  *(uint *)(param_1 + 0x10) = param_3;
  *(uint *)(param_1 + 0x14) = param_4;
  *(uint *)(param_1 + 0x1c) = param_6;
  if (param_2 == 0x20) {
    *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
  }
  else {
    *(int *)(param_1 + 0x20) = (1 << ((byte)param_2 & 0x1f)) + -1;
  }
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & ~(param_3 | param_4 | param_5 | param_6);
  if (param_3 == 0) {
    param_1[8] = 0;
    param_1[0xc] = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  else {
    uVar2 = 1;
    cVar4 = '\0';
    uVar1 = param_3 & 1;
    while (uVar1 == 0) {
      uVar2 = uVar2 * 2;
      cVar4 = cVar4 + '\x01';
      uVar1 = param_3 & uVar2;
    }
    param_1[0xc] = cVar4;
    cVar4 = '\0';
    for (; (param_3 & uVar2) != 0; uVar2 = uVar2 * 2) {
      cVar4 = cVar4 + '\x01';
    }
    param_1[8] = cVar4;
  }
  if (param_4 == 0) {
    param_1[9] = 0;
    param_1[0xd] = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  else {
    uVar2 = 1;
    cVar4 = '\0';
    uVar1 = param_4 & 1;
    while (uVar1 == 0) {
      uVar2 = uVar2 * 2;
      cVar4 = cVar4 + '\x01';
      uVar1 = param_4 & uVar2;
    }
    param_1[0xd] = cVar4;
    cVar4 = '\0';
    for (; (param_4 & uVar2) != 0; uVar2 = uVar2 * 2) {
      cVar4 = cVar4 + '\x01';
    }
    param_1[9] = cVar4;
  }
  if (param_5 == 0) {
    param_1[10] = 0;
    param_1[0xe] = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  else {
    uVar1 = 1;
    cVar4 = '\0';
    if ((param_5 & 1) == 0) {
      cVar4 = '\0';
      do {
        uVar1 = uVar1 * 2;
        cVar4 = cVar4 + '\x01';
      } while ((param_5 & uVar1) == 0);
    }
    param_1[0xe] = cVar4;
    cVar4 = '\0';
    for (; (param_5 & uVar1) != 0; uVar1 = uVar1 * 2) {
      cVar4 = cVar4 + '\x01';
    }
    param_1[10] = cVar4;
  }
  if (param_6 == 0) {
    param_1[0xb] = 0;
    param_1[0xf] = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  else {
    uVar2 = 1;
    cVar4 = '\0';
    uVar1 = param_6 & 1;
    while (uVar1 == 0) {
      uVar2 = uVar2 * 2;
      cVar4 = cVar4 + '\x01';
      uVar1 = param_6 & uVar2;
    }
    param_1[0xf] = cVar4;
    cVar4 = '\0';
    for (; (param_6 & uVar2) != 0; uVar2 = uVar2 * 2) {
      cVar4 = cVar4 + '\x01';
    }
    param_1[0xb] = cVar4;
  }
  uVar1 = *(uint *)(param_1 + 0x20);
  if (uVar1 == 0) {
    *(undefined4 *)(param_1 + 0x20) = 0;
    param_1[7] = 0;
    param_1[6] = 0;
    return 0;
  }
  uVar3 = 1;
  cVar4 = '\0';
  uVar2 = uVar1 & 1;
  while (uVar2 == 0) {
    uVar3 = uVar3 * 2;
    cVar4 = cVar4 + '\x01';
    uVar2 = uVar1 & uVar3;
  }
  param_1[6] = cVar4;
  cVar4 = '\0';
  for (; (uVar1 & uVar3) != 0; uVar3 = uVar3 * 2) {
    cVar4 = cVar4 + '\x01';
  }
  param_1[7] = cVar4;
  return 0;
}

