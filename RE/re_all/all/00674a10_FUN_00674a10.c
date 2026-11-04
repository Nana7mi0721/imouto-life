
void FUN_00674a10(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  short *psVar3;
  ushort local_202;
  short local_200 [256];
  
  uVar1 = *(uint *)(param_1 + 0x74);
  if ((uVar1 & 1) == 0) {
    FUN_00668a30(param_1,s_missing_IHDR_00a0ce1c);
  }
  else {
    if (((uVar1 & 4) != 0) || ((uVar1 & 2) == 0)) {
      FUN_00673140(param_1,param_3);
      FUN_00668b90(param_1,s_out_of_place_00a0cdb4);
      return;
    }
    if ((param_2 != 0) && ((*(byte *)(param_2 + 8) & 0x40) != 0)) {
      FUN_00673140(param_1,param_3);
      FUN_00668b90(param_1,s_duplicate_00a0bdf4);
      return;
    }
  }
  uVar1 = param_3 >> 1;
  if ((uVar1 != *(ushort *)(param_1 + 0x148)) || (0x100 < uVar1)) {
    FUN_00673140(param_1,param_3);
    FUN_00668b90(param_1,s_invalid_00a0cdac);
    return;
  }
  if (uVar1 != 0) {
    psVar3 = local_200;
    do {
      FUN_00673110(param_1,&local_202,2);
      *psVar3 = local_202 * 0x100 + (local_202 >> 8);
      psVar3 = psVar3 + 1;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  iVar2 = FUN_00673140(param_1,0);
  if (iVar2 == 0) {
    FUN_00672040(param_1,param_2,local_200);
    return;
  }
  return;
}

