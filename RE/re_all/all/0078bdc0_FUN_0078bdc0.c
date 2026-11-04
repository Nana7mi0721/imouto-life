
void __thiscall FUN_0078bdc0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 unaff_retaddr;
  undefined1 local_60 [2];
  undefined1 auStack_5e [2];
  undefined1 auStack_5c [12];
  undefined1 local_50 [16];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = *(int *)(param_1 + 8);
  if (iVar2 == *(int *)(param_1 + 0xc)) {
    if (iVar2 == 0) {
      iVar2 = 1;
    }
    else {
      iVar2 = iVar2 * 2;
    }
    FUN_0078e010(iVar2);
  }
  piVar1 = (int *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 8) * 4);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  FUN_005f5190(&local_40,0x10,3,FUN_0061ddb0);
  local_40 = *(undefined4 *)(param_2 + 4);
  local_3c = *(undefined4 *)(param_2 + 8);
  local_38 = *(undefined4 *)(param_2 + 0xc);
  local_34 = *(undefined4 *)(param_2 + 0x10);
  local_30 = *(undefined4 *)(param_2 + 0x14);
  local_2c = *(undefined4 *)(param_2 + 0x18);
  local_28 = *(undefined4 *)(param_2 + 0x1c);
  local_24 = *(undefined4 *)(param_2 + 0x20);
  local_20 = *(undefined4 *)(param_2 + 0x24);
  local_1c = *(undefined4 *)(param_2 + 0x28);
  local_18 = *(undefined4 *)(param_2 + 0x2c);
  local_14 = *(undefined4 *)(param_2 + 0x30);
  local_10 = *(undefined4 *)(param_2 + 0x34);
  local_c = *(undefined4 *)(param_2 + 0x38);
  local_8 = *(undefined4 *)(param_2 + 0x3c);
  local_4 = *(undefined4 *)(param_2 + 0x40);
  (**(code **)(**(int **)(param_2 + 0xc0) + 4))(&local_40,local_50,local_60);
  uVar3 = (**(code **)(**(int **)(param_1 + 0x4c) + 4))
                    (auStack_5c,local_60 + -0xc,*(undefined4 *)(*(int *)(param_2 + 0xc0) + 4),
                     param_2,local_4,unaff_retaddr,*(undefined4 *)(param_1 + 0x18),0);
  *(undefined4 *)(param_2 + 0xbc) = uVar3;
  return;
}

