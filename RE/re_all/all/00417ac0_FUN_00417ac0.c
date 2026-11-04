
/* WARNING: Removing unreachable block (ram,0x00417eaa) */
/* WARNING: Removing unreachable block (ram,0x00417f07) */
/* WARNING: Removing unreachable block (ram,0x00417f0f) */
/* WARNING: Removing unreachable block (ram,0x00417f17) */
/* WARNING: Removing unreachable block (ram,0x00417f29) */
/* WARNING: Removing unreachable block (ram,0x00417f20) */
/* WARNING: Removing unreachable block (ram,0x00417f4b) */
/* WARNING: Removing unreachable block (ram,0x00417fa1) */
/* WARNING: Removing unreachable block (ram,0x00417f98) */
/* WARNING: Removing unreachable block (ram,0x00417fca) */
/* WARNING: Removing unreachable block (ram,0x00417aed) */

undefined4 __thiscall FUN_00417ac0(int param_1,char *param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  int local_4c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_14;
  int local_10;
  undefined1 local_9;
  FILE *local_8;
  
  local_10 = 0;
  DAT_00a117ec = 1;
  DAT_00a11790 = 0;
  FUN_004cf550();
  FUN_0046b720();
  for (local_1c = 0; local_1c < 3; local_1c = local_1c + 1) {
    for (local_20 = 0; local_20 < *(int *)(param_1 + 0x1420); local_20 = local_20 + 1) {
      for (local_24 = 0; local_24 < *(int *)(param_1 + 0x1424); local_24 = local_24 + 1) {
        if (DAT_00a117ec == 0) {
          DAT_00a1179c = 4;
          sVar5 = 4;
          iVar3 = local_20;
          iVar4 = local_24;
          FUN_004cde80(local_1c);
          FUN_004cde80(iVar3);
          pvVar1 = (void *)FUN_004ce990(iVar4);
          _memcpy((void *)((int)DAT_00a0f830 + DAT_00a11790),pvVar1,sVar5);
        }
        DAT_00a11790 = DAT_00a11790 + 4;
      }
    }
  }
  for (local_28 = 0; local_28 < *(int *)(param_1 + 0x1428); local_28 = local_28 + 1) {
    FUN_004cf5e0(local_28);
    FUN_0046b8e0();
  }
  local_10 = DAT_00a11790;
  if (DAT_00a117ec == 0) {
    _free(DAT_00a0f830);
  }
  DAT_00a117ec = 0;
  DAT_00a11790 = 0;
  DAT_00a0f830 = _malloc((size_t)(&DAT_009a6b40 + local_10));
  _memset(DAT_00a0f830,0,(size_t)(&DAT_009a6b40 + local_10));
  local_14 = 100;
  DAT_00a11790 = DAT_00a11790 + 0x14;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 4;
    _memcpy((void *)((int)DAT_00a0f830 + DAT_00a11790),&local_14,4);
  }
  DAT_00a11790 = DAT_00a11790 + 4;
  local_9 = 0x65;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy((void *)((int)DAT_00a0f830 + DAT_00a11790),&local_9,1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  FUN_0046b720();
  for (local_2c = 0; local_2c < 3; local_2c = local_2c + 1) {
    for (local_30 = 0; local_30 < *(int *)(param_1 + 0x1420); local_30 = local_30 + 1) {
      for (local_34 = 0; local_34 < *(int *)(param_1 + 0x1424); local_34 = local_34 + 1) {
        if (DAT_00a117ec == 0) {
          DAT_00a1179c = 4;
          sVar5 = 4;
          iVar3 = local_30;
          iVar4 = local_34;
          FUN_004cde80(local_2c);
          FUN_004cde80(iVar3);
          pvVar1 = (void *)FUN_004ce990(iVar4);
          _memcpy((void *)((int)DAT_00a0f830 + DAT_00a11790),pvVar1,sVar5);
        }
        DAT_00a11790 = DAT_00a11790 + 4;
      }
    }
  }
  for (local_38 = 0; local_38 < *(int *)(param_1 + 0x1428); local_38 = local_38 + 1) {
    FUN_004cf5e0(local_38);
    FUN_0046b8e0();
  }
  local_9 = 0x66;
  if (DAT_00a117ec == 0) {
    DAT_00a1179c = 1;
    _memcpy((void *)((int)DAT_00a0f830 + DAT_00a11790),&local_9,1);
  }
  DAT_00a11790 = DAT_00a11790 + 1;
  for (local_4c = 0; local_4c < 0x14; local_4c = local_4c + 1) {
    *(undefined1 *)((int)DAT_00a0f830 + local_4c) = 0;
  }
  *(undefined1 *)((int)DAT_00a0f830 + 10) = 0x57;
  *(undefined1 *)((int)DAT_00a0f830 + 0xb) = 0x4f;
  *(undefined1 *)((int)DAT_00a0f830 + 0xc) = 0x4c;
  *(undefined1 *)((int)DAT_00a0f830 + 0xd) = 0x46;
  *(undefined1 *)((int)DAT_00a0f830 + 0xe) = 0x4d;
  local_8 = _fopen(param_2,"wb");
  if (local_8 == (FILE *)0x0) {
    uVar2 = 0;
  }
  else {
    _fwrite(DAT_00a0f830,DAT_00a11790,1,local_8);
    _fclose(local_8);
    if (DAT_00a117ec == 0) {
      _free(DAT_00a0f830);
    }
    uVar2 = 1;
  }
  return uVar2;
}

