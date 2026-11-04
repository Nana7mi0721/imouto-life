
void FUN_00673a70(uint param_1,undefined4 param_2,int param_3)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = param_1;
  if ((*(uint *)(param_1 + 0x74) & 1) == 0) {
    FUN_00668a30(param_1,s_missing_IHDR_00a0ce1c);
  }
  else if ((*(uint *)(param_1 + 0x74) & 6) != 0) {
    FUN_00673140(param_1,param_3);
    FUN_00668b90(uVar2,s_out_of_place_00a0cdb4);
    return;
  }
  if (param_3 != 1) {
    FUN_00673140(uVar2,param_3);
    FUN_00668b90(uVar2,s_invalid_00a0cdac);
    return;
  }
  FUN_00673110(uVar2,&param_1,1);
  iVar3 = FUN_00673140(uVar2,0);
  if ((iVar3 == 0) && (uVar1 = *(ushort *)(uVar2 + 0x326), (uVar1 & 0x8000) == 0)) {
    if ((uVar1 & 4) != 0) {
      *(ushort *)(uVar2 + 0x326) = uVar1 | 0x8000;
      FUN_006699d0(uVar2,param_2);
      FUN_00668b90(uVar2,s_too_many_profiles_00a0ce64);
      return;
    }
    FUN_0066a1d0(uVar2,uVar2 + 0x2dc,param_1 & 0xff);
    FUN_006699d0(uVar2,param_2);
  }
  return;
}

