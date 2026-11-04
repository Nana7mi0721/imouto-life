
undefined4 FUN_005364a0(int param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined2 *puVar7;
  uint local_220;
  uint local_218;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined2 local_200 [256];
  
  FUN_0056bb10(&DAT_007d5c58);
  FUN_0056bfd0();
  bVar1 = DAT_00a4bca8 < 1;
  if (bVar1) {
    uVar3 = local_220;
    uVar4 = local_220;
    uVar5 = local_220;
    uVar6 = local_220;
  }
  else {
    iVar2 = FUN_0052eda0(DAT_00a4bca8);
    FUN_0056cf70(local_200,0x200,iVar2 + 0x92f60);
    local_218 = (uint)*(byte *)(iVar2 + 0x93168);
    local_220 = *(uint *)(iVar2 + 0x93188);
    uVar3 = (uint)*(ushort *)(iVar2 + 0x93160);
    uVar4 = (uint)*(ushort *)(iVar2 + 0x9316c);
    uVar5 = *(uint *)(iVar2 + 0x93184);
    uVar6 = (uint)*(ushort *)(iVar2 + 0x93162);
  }
  FUN_00580eb0(8,0);
  if (param_1 == 0) {
    local_20c = DAT_00a4b770;
    local_210 = DAT_00a4b768;
    local_214 = DAT_00a4b764;
    local_208 = DAT_00a4b774;
    local_204 = DAT_00a4b778;
    if (bVar1) {
      puVar7 = &DAT_00a4bcb0;
      uVar6 = DAT_00a4beb4;
      uVar3 = DAT_00a4bebc;
      uVar5 = DAT_00a4bec4;
      uVar4 = DAT_00a4becc;
      local_220 = DAT_00a4bed8;
      local_218 = DAT_00a4bee0;
    }
    else {
      puVar7 = local_200;
    }
    DAT_00a4bca8 = FUN_00530090(&local_214,puVar7,uVar6,uVar3,uVar5,uVar4,local_220,local_218,
                                0xffffffff,0);
    FUN_00580830(DAT_00a4bca8,&DAT_00a4bca8);
  }
  FUN_0056bfe0();
  FUN_0056bb10(&DAT_007d5c30);
  return 0;
}

