
void FUN_006ba8a0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int local_308;
  int local_304;
  undefined4 local_300 [192];
  
  puVar3 = (undefined4 *)(param_1 + 0xdc);
  iVar4 = 3;
  puVar5 = local_300;
  do {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    iVar4 = iVar4 + -1;
    puVar6 = puVar5;
    for (iVar2 = 0x40; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = uVar1;
      puVar6 = puVar6 + 1;
    }
    puVar5 = puVar5 + 0x40;
  } while (iVar4 != 0);
  iVar4 = param_1 + 0xc9b4;
  local_308 = FUN_006bf0c0(iVar4,4);
  local_304 = FUN_006bf0c0(iVar4,4);
  *(undefined4 *)(param_1 + 0xce08) = 0;
  uVar1 = FUN_006ba990(param_1,&local_308,local_300);
  local_308 = FUN_006bf0c0(iVar4,4);
  local_304 = FUN_006bf0c0(iVar4,4);
  iVar4 = 1;
  iVar2 = 1;
  do {
    local_308 = local_308 + 0x10;
    local_304 = local_304 + 0x10;
    if (iVar4 < (int)(uint)(byte)(&UNK_00832280)[iVar2]) {
      do {
        uVar1 = FUN_006bac80(param_1,iVar4,&local_308,local_300,uVar1);
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)(uint)(byte)(&UNK_00832280)[iVar2]);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return;
}

