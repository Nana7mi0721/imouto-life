
void __thiscall FUN_005e1f70(int param_1,char param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  
  iVar3 = *(int *)(param_1 + 0xb0);
  if (iVar3 == -1) {
    iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x19c);
  }
  if (DAT_00dda458 < 0) {
    FUN_00582be0();
    FUN_0059d430();
  }
  if (param_2 != '\0') {
    *(undefined4 *)(unaff_ESI + 0x30) = 3;
    *(undefined4 *)(unaff_ESI + 0x38) = 0;
    *(int *)(unaff_ESI + 0x34) = DAT_00dda458;
    FUN_005a7d70();
    FUN_0059b980();
    return;
  }
  *(undefined4 *)(unaff_ESI + 0x30) = 1;
  *(int *)(unaff_ESI + 0x34) = DAT_00dda458;
  *(undefined4 *)(unaff_ESI + 0x38) = 0;
  *(undefined4 *)(unaff_ESI + 0x3c) = 0;
  *(undefined2 *)(unaff_ESI + 0x46) = 2;
  *(undefined2 *)(unaff_ESI + 0x48) = 0;
  *(undefined2 *)(unaff_ESI + 0x4a) = 4;
  *(undefined2 *)(unaff_ESI + 0x40) = 2;
  *(undefined2 *)(unaff_ESI + 0x42) = 0;
  *(undefined2 *)(unaff_ESI + 0x44) = 4;
  iVar2 = 1;
  if (iVar3 == 0xb) {
    if (*(int *)(unaff_ESI + 0x14) == -1) goto LAB_005e204e;
    *(undefined2 *)(unaff_ESI + 0x60) = 3;
    *(undefined2 *)(unaff_ESI + 0x62) = 0xe;
    *(undefined2 *)(unaff_ESI + 0x5a) = 0;
    *(undefined2 *)(unaff_ESI + 0x5c) = 2;
  }
  else {
    if (*(int *)(unaff_ESI + 0x14) == -1) goto LAB_005e204e;
    *(undefined2 *)(unaff_ESI + 0x60) = 0;
    *(undefined2 *)(unaff_ESI + 0x62) = 2;
    *(undefined2 *)(unaff_ESI + 0x5a) = 3;
    *(undefined2 *)(unaff_ESI + 0x5c) = 4;
  }
  *(undefined2 *)(unaff_ESI + 0x58) = 1;
  *(undefined2 *)(unaff_ESI + 0x5e) = 1;
  *(undefined4 *)(unaff_ESI + 0x50) = 0;
  iVar2 = 2;
  *(undefined4 *)(unaff_ESI + 0x4c) = 0;
LAB_005e204e:
  puVar1 = (undefined4 *)(unaff_ESI + 0x34 + iVar2 * 0x18);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  *(undefined2 *)((int)puVar1 + 0x12) = 2;
  *(undefined2 *)(puVar1 + 5) = 0;
  *(undefined2 *)((int)puVar1 + 0x16) = 1;
  *(undefined2 *)(puVar1 + 3) = 2;
  *(undefined2 *)((int)puVar1 + 0xe) = 0;
  *(undefined2 *)(puVar1 + 4) = 1;
  *(int *)(unaff_ESI + 0x30) = iVar2 + 1;
  FUN_005a7d70();
  return;
}

