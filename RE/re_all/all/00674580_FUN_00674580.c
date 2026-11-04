
void FUN_00674580(int param_1,int param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  undefined1 local_108;
  undefined1 local_107;
  undefined1 local_106;
  undefined1 local_105;
  undefined1 local_104;
  undefined1 local_103;
  ushort local_102;
  undefined1 local_100 [256];
  
  if ((*(uint *)(param_1 + 0x74) & 1) == 0) {
    FUN_00668a30(param_1,s_missing_IHDR_00a0ce1c);
  }
  else {
    if ((*(uint *)(param_1 + 0x74) & 4) != 0) {
      FUN_00673140(param_1,param_3);
      FUN_00668b90(param_1,s_out_of_place_00a0cdb4);
      return;
    }
    if ((param_2 != 0) && ((*(byte *)(param_2 + 8) & 0x10) != 0)) {
      FUN_00673140(param_1,param_3);
      FUN_00668b90(param_1,s_duplicate_00a0bdf4);
      return;
    }
  }
  cVar1 = *(char *)(param_1 + 0x157);
  if (cVar1 == '\0') {
    if (param_3 != 2) {
      FUN_00673140(param_1,param_3);
      FUN_00668b90(param_1,s_invalid_00a0cdac);
      return;
    }
    FUN_00673110(param_1,&local_102,2);
    *(undefined2 *)(param_1 + 0x150) = 1;
    *(ushort *)(param_1 + 0x1c0) = local_102 * 0x100 + (local_102 >> 8);
  }
  else if (cVar1 == '\x02') {
    if (param_3 != 6) {
      FUN_00673140(param_1,param_3);
      FUN_00668b90(param_1,s_invalid_00a0cdac);
      return;
    }
    FUN_00673110(param_1,&local_108,6);
    *(ushort *)(param_1 + 0x1ba) = CONCAT11(local_108,local_107);
    *(undefined2 *)(param_1 + 0x150) = 1;
    *(ushort *)(param_1 + 0x1bc) = CONCAT11(local_106,local_105);
    *(ushort *)(param_1 + 0x1be) = CONCAT11(local_104,local_103);
  }
  else {
    if (cVar1 != '\x03') {
      FUN_00673140(param_1,param_3);
      FUN_00668b90(param_1,s_invalid_with_alpha_channel_00a0cfa4);
      return;
    }
    if ((*(byte *)(param_1 + 0x74) & 2) == 0) {
      FUN_00673140(param_1,param_3);
      FUN_00668b90(param_1,s_out_of_place_00a0cdb4);
      return;
    }
    if (((*(ushort *)(param_1 + 0x148) < param_3) || (0x100 < param_3)) || (param_3 == 0)) {
      FUN_00673140(param_1,param_3);
      FUN_00668b90(param_1,s_invalid_00a0cdac);
      return;
    }
    FUN_00673110(param_1,local_100,param_3);
    *(short *)(param_1 + 0x150) = (short)param_3;
  }
  iVar2 = FUN_00673140(param_1,0);
  if (iVar2 == 0) {
    FUN_00672b20(param_1,param_2,local_100,*(undefined2 *)(param_1 + 0x150),param_1 + 0x1b8);
    return;
  }
  *(undefined2 *)(param_1 + 0x150) = 0;
  return;
}

