
void FUN_00673620(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = param_1;
  if ((*(uint *)(param_1 + 0x74) & 1) == 0) {
    FUN_00668a30(param_1,s_missing_IHDR_00a0ce1c);
  }
  else if ((*(uint *)(param_1 + 0x74) & 6) != 0) {
    FUN_00673140(param_1,param_3);
    FUN_00668b90(iVar1,s_out_of_place_00a0cdb4);
    return;
  }
  if (param_3 != 4) {
    FUN_00673140(iVar1,param_3);
    FUN_00668b90(iVar1,s_invalid_00a0cdac);
    return;
  }
  FUN_00673110(iVar1,&param_1,4);
  iVar2 = FUN_00673140(iVar1,0);
  if (iVar2 == 0) {
    uVar3 = FUN_006736c0(0,&param_1);
    FUN_00669850(iVar1,iVar1 + 0x2dc,uVar3);
    FUN_006699d0(iVar1,param_2);
  }
  return;
}

