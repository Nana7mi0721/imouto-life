
int __thiscall
FUN_00601860(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_00601ee0(param_2,param_3,param_4,param_5,param_6,0);
  *(undefined ***)(param_1 + 0x98) = &PTR_LAB_008033d0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined1 *)(param_1 + 0xa0) = 0;
  *(undefined1 *)(param_1 + 0xa1) = 0;
  puVar2 = (undefined4 *)(param_1 + 0xa8);
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return param_1;
}

