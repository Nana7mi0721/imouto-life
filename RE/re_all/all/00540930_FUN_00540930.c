
void FUN_00540930(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  FUN_005408d0(param_1,param_2);
  puVar1 = (undefined4 *)FUN_0052c690();
  puVar3 = (undefined4 *)(param_1 + 0x30);
  for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined4 *)FUN_0052c790();
  *(undefined4 *)(param_1 + 100) = *puVar1;
  *(undefined4 *)(param_1 + 0x68) = puVar1[1];
  *(undefined4 *)(param_1 + 0x6c) = puVar1[2];
  *(undefined4 *)(param_1 + 0x70) = puVar1[3];
  *(undefined4 *)(param_1 + 0x74) = puVar1[4];
  *(undefined4 *)(param_1 + 0x78) = puVar1[5];
  puVar1 = (undefined4 *)FUN_0052c7a0();
  *(undefined4 *)(param_1 + 0x7c) = *puVar1;
  *(undefined4 *)(param_1 + 0x80) = puVar1[1];
  *(undefined4 *)(param_1 + 0x84) = puVar1[2];
  *(undefined4 *)(param_1 + 0x88) = puVar1[3];
  *(undefined4 *)(param_1 + 0x8c) = puVar1[4];
  *(undefined4 *)(param_1 + 0x90) = puVar1[5];
  *(undefined4 *)(param_1 + 0x94) = DAT_00a52a54;
  *(undefined4 *)(param_1 + 0x98) = DAT_00a52a58;
  *(undefined4 *)(param_1 + 0x9c) = DAT_00a52a5c;
  return;
}

