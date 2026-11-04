
void FUN_0079b110(int param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  undefined1 uVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  undefined1 local_30 [16];
  short local_20 [16];
  
  if ((param_4 == 0) && (*(int *)(param_1 + 0x964 + param_3 * 4) == 0)) {
    iVar4 = FUN_007a2170(param_2,&DAT_008377c8,8);
  }
  else {
    iVar4 = FUN_007a2170(param_2,&DAT_008377c4,8);
    iVar4 = iVar4 + 2;
  }
  cVar2 = (char)(iVar4 >> 1);
  *(char *)(param_1 + 0xacd) = cVar2;
  *(byte *)(param_1 + 0xace) = (byte)iVar4 & 1;
  if (param_5 == 2) {
    uVar1 = FUN_007a2170(param_2,&DAT_008380e0,8);
    *(undefined1 *)(param_1 + 0xab0) = uVar1;
  }
  else {
    cVar2 = FUN_007a2170(param_2,&DAT_008380c8 + cVar2 * 8,8);
    *(char *)(param_1 + 0xab0) = cVar2 << 3;
    cVar2 = FUN_007a2170(param_2,&DAT_008377fc,8);
    *(char *)(param_1 + 0xab0) = *(char *)(param_1 + 0xab0) + cVar2;
  }
  iVar4 = 1;
  if (1 < *(int *)(param_1 + 0x914)) {
    do {
      uVar1 = FUN_007a2170(param_2,&DAT_008380e0,8);
      *(undefined1 *)(param_1 + 0xab0 + iVar4) = uVar1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x914));
  }
  cVar2 = FUN_007a2170(param_2,((int)*(char *)(param_1 + 0xacd) >> 1) *
                               (int)**(short **)(param_1 + 0xaac) +
                               *(int *)(*(short **)(param_1 + 0xaac) + 6),8);
  *(char *)(param_1 + 0xab8) = cVar2;
  FUN_0079ef00(local_20,local_30,*(undefined4 *)(param_1 + 0xaac),(int)cVar2);
  iVar4 = *(int *)(param_1 + 0xaac);
  iVar6 = 0;
  if (0 < *(short *)(iVar4 + 2)) {
    psVar5 = local_20;
    do {
      iVar4 = FUN_007a2170(param_2,*(int *)(iVar4 + 0x18) + (int)*psVar5,8);
      if (iVar4 == 0) {
        iVar4 = FUN_007a2170(param_2,&DAT_00837804,8);
        iVar4 = -iVar4;
      }
      else if (iVar4 == 8) {
        iVar4 = FUN_007a2170(param_2,&DAT_00837804,8);
        iVar4 = iVar4 + 8;
      }
      psVar5 = psVar5 + 1;
      *(char *)(param_1 + 0xab9 + iVar6) = (char)iVar4 + -4;
      iVar4 = *(int *)(param_1 + 0xaac);
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(short *)(iVar4 + 2));
  }
  if (*(int *)(param_1 + 0x914) == 4) {
    uVar1 = FUN_007a2170(param_2,&DAT_008377cc,8);
    *(undefined1 *)(param_1 + 0xacf) = uVar1;
  }
  else {
    *(undefined1 *)(param_1 + 0xacf) = 4;
  }
  if (*(char *)(param_1 + 0xacd) == '\x02') {
    if (((param_5 == 2) && (*(int *)(param_1 + 0x95c) == 2)) &&
       (sVar3 = FUN_007a2170(param_2,&DAT_00838070,8), 0 < sVar3)) {
      *(short *)(param_1 + 0xaca) = *(short *)(param_1 + 0x960) + sVar3 + -9;
    }
    else {
      sVar3 = FUN_007a2170(param_2,&DAT_00838050,8);
      *(short *)(param_1 + 0xaca) = sVar3 * (short)(*(int *)(param_1 + 0x90c) >> 1);
      sVar3 = FUN_007a2170(param_2,*(undefined4 *)(param_1 + 0x94c),8);
      *(short *)(param_1 + 0xaca) = *(short *)(param_1 + 0xaca) + sVar3;
    }
    *(undefined2 *)(param_1 + 0x960) = *(undefined2 *)(param_1 + 0xaca);
    uVar1 = FUN_007a2170(param_2,*(undefined4 *)(param_1 + 0x950),8);
    *(undefined1 *)(param_1 + 0xacc) = uVar1;
    uVar1 = FUN_007a2170(param_2,&DAT_00837e54,8);
    *(undefined1 *)(param_1 + 0xad0) = uVar1;
    iVar4 = 0;
    if (0 < *(int *)(param_1 + 0x914)) {
      do {
        uVar1 = FUN_007a2170(param_2,(&PTR_DAT_00837ecc)[*(char *)(param_1 + 0xad0)],8);
        *(undefined1 *)(param_1 + 0xab4 + iVar4) = uVar1;
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(param_1 + 0x914));
    }
    if (param_5 == 0) {
      uVar1 = FUN_007a2170(param_2,&DAT_008377c0,8);
      *(undefined1 *)(param_1 + 0xad1) = uVar1;
    }
    else {
      *(undefined1 *)(param_1 + 0xad1) = 0;
    }
  }
  *(int *)(param_1 + 0x95c) = (int)*(char *)(param_1 + 0xacd);
  uVar1 = FUN_007a2170(param_2,&DAT_008377e8,8);
  *(undefined1 *)(param_1 + 0xad2) = uVar1;
  return;
}

