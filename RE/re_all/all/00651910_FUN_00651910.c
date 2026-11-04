
int FUN_00651910(int param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = FUN_00652630(param_1,0);
  if (iVar1 == 0) {
    return -1;
  }
  if (*(uint *)(param_1 + 0xa8) <= param_2) {
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFReadEncodedStrip",
                 s__lu__Strip_out_of_range__max__lu_00a06d28,param_2,*(uint *)(param_1 + 0xa8));
    return -1;
  }
  uVar5 = *(uint *)(param_1 + 0x3c);
  uVar4 = *(uint *)(param_1 + 100);
  if (uVar5 < *(uint *)(param_1 + 100)) {
    uVar4 = uVar5;
  }
  uVar2 = ((uVar5 - 1) + uVar4) / uVar4;
  uVar5 = uVar5 - (param_2 % uVar2) * uVar4;
  if (uVar4 < uVar5) {
    uVar5 = uVar4;
  }
  iVar1 = FUN_006529c0(param_1,uVar5);
  if (iVar1 == 0) {
    return -1;
  }
  if ((param_4 != -1) && (param_4 < iVar1)) {
    iVar1 = param_4;
  }
  iVar3 = FUN_00651ba0(param_1,param_2);
  if (iVar3 == 0) {
    return -1;
  }
  iVar3 = (**(code **)(param_1 + 0x21c))(param_1,param_3,iVar1,param_2 / uVar2);
  if (iVar3 < 1) {
    return -1;
  }
  (**(code **)(param_1 + 0x28c))(param_1,param_3,iVar1);
  return iVar1;
}

