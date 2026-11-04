
void FUN_00674810(int param_1,int param_2,int param_3)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 local_14;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_c [2];
  ushort local_a;
  ushort local_8;
  ushort local_6;
  ushort local_4;
  
  uVar1 = *(uint *)(param_1 + 0x74);
  if ((uVar1 & 1) == 0) {
    FUN_00668a30(param_1,s_missing_IHDR_00a0ce1c);
  }
  else {
    if (((uVar1 & 4) != 0) || ((*(char *)(param_1 + 0x157) == '\x03' && ((uVar1 & 2) == 0)))) {
      FUN_00673140(param_1,param_3);
      FUN_00668b90(param_1,s_out_of_place_00a0cdb4);
      return;
    }
    if ((param_2 != 0) && ((*(byte *)(param_2 + 8) & 0x20) != 0)) {
      FUN_00673140(param_1,param_3);
      FUN_00668b90(param_1,s_duplicate_00a0bdf4);
      return;
    }
  }
  if (*(byte *)(param_1 + 0x157) == 3) {
    iVar3 = 1;
  }
  else {
    iVar3 = (uint)(*(byte *)(param_1 + 0x157) & 2 | 1) << 1;
  }
  if (param_3 != iVar3) {
    FUN_00673140(param_1,param_3);
    FUN_00668b90(param_1,s_invalid_00a0cdac);
    return;
  }
  FUN_00673110(param_1,&local_14,iVar3);
  iVar3 = FUN_00673140(param_1,0);
  if (iVar3 != 0) {
    return;
  }
  local_c[0] = (undefined1)local_14;
  uVar2 = (ushort)local_14;
  if (*(byte *)(param_1 + 0x157) == 3) {
    if ((param_2 == 0) || (*(ushort *)(param_2 + 0x14) == 0)) {
      local_6 = 0;
      local_8 = 0;
      local_a = 0;
    }
    else {
      if (*(ushort *)(param_2 + 0x14) <= (uVar2 & 0xff)) {
        FUN_00668b90(param_1,s_invalid_index_00a0cfc0);
        return;
      }
      pbVar4 = (byte *)((local_14 & 0xff) * 3 + *(int *)(param_1 + 0x144));
      local_a = (ushort)*pbVar4;
      local_8 = (ushort)pbVar4[1];
      local_6 = (ushort)pbVar4[2];
    }
  }
  else {
    local_c[0] = 0;
    if ((*(byte *)(param_1 + 0x157) & 2) == 0) {
      local_a = uVar2 * 0x100 + ((ushort)(local_14 >> 8) & 0xff);
      local_8 = local_a;
      local_6 = local_a;
      local_4 = local_a;
      goto LAB_006749d0;
    }
    local_a = uVar2 * 0x100 + (ushort)(byte)(local_14 >> 8);
    local_8 = CONCAT11(local_14._2_1_,local_14._3_1_);
    local_6 = CONCAT11(local_10,local_f);
  }
  local_4 = 0;
LAB_006749d0:
  FUN_00672000(param_1,param_2,local_c);
  return;
}

