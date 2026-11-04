
uint FUN_006c1190(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *_Memory;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined8 uVar11;
  undefined4 local_184 [7];
  undefined4 local_168 [90];
  
  uVar1 = *(uint *)(param_1 + 0x21d4);
  _Memory = _malloc(uVar1 << 5);
  if (_Memory == (undefined4 *)0x0) {
    return 0xffffff7f;
  }
  puVar9 = (undefined4 *)(param_1 + 0x40);
  uVar2 = *(undefined4 *)(param_1 + 0x74);
  puVar8 = puVar9;
  puVar10 = local_184;
  for (iVar7 = 7; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar10 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar10 = puVar10 + 1;
  }
  puVar8 = (undefined4 *)(param_1 + 0x88);
  puVar10 = local_168;
  for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar10 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar10 = puVar10 + 1;
  }
  uVar3 = *(undefined4 *)(param_1 + 0x70);
  uVar4 = *(undefined4 *)(param_1 + 0x34);
  uVar5 = *(undefined4 *)(param_1 + 0x30);
  puVar8 = (undefined4 *)(param_1 + 0x1f0);
  puVar10 = _Memory;
  for (iVar7 = (uVar1 & 0x7ffffff) << 3; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar10 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar10 = puVar10 + 1;
  }
  for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
    puVar8 = (undefined4 *)((int)puVar8 + 1);
    puVar10 = (undefined4 *)((int)puVar10 + 1);
  }
  FUN_006a86a0(puVar9);
  FUN_006a83f0(param_1 + 0x88,0xffffffff);
  uVar6 = FUN_006c1310(param_1);
  FUN_006a8490(param_1 + 0x88);
  FUN_006a86c0(puVar9);
  puVar8 = local_184;
  for (iVar7 = 7; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
  }
  puVar9 = local_168;
  puVar8 = (undefined4 *)(param_1 + 0x88);
  for (iVar7 = 0x5a; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar8 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar8 = puVar8 + 1;
  }
  *(uint *)(param_1 + 0x21d4) = uVar1;
  *(undefined4 *)(param_1 + 0x30) = uVar5;
  *(undefined4 *)(param_1 + 0x34) = uVar4;
  puVar9 = _Memory;
  puVar8 = (undefined4 *)(param_1 + 0x1f0);
  for (iVar7 = (uVar1 & 0x7ffffff) << 3; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar8 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar8 = puVar8 + 1;
  }
  for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
    *(undefined1 *)puVar8 = *(undefined1 *)puVar9;
    puVar9 = (undefined4 *)((int)puVar9 + 1);
    puVar8 = (undefined4 *)((int)puVar8 + 1);
  }
  _free(_Memory);
  iVar7 = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(iVar7 + 0x20);
  *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(iVar7 + 0x24);
  *(undefined4 *)(param_1 + 0x70) = uVar3;
  *(undefined4 *)(param_1 + 0x74) = uVar2;
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(iVar7 + 0x34);
  if (-1 < (int)uVar6) {
    uVar11 = FUN_006c0540(param_1,0);
    iVar7 = (**(code **)(param_1 + 4))(*(undefined4 *)(param_1 + 0x10),uVar11);
    uVar6 = (-1 < iVar7) - 1 & 0xffffff80;
  }
  return uVar6;
}

