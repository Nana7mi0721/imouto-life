
int FUN_0060a7c0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined8 uVar3;
  
  iVar1 = param_1 + 0x34;
  FUN_0056da60(iVar1,s_D__DxLib_Develop_Source_Library__00a06048,0x39f6);
  if (*(int *)(param_1 + 8) != 0) {
    FUN_0056dac0(iVar1);
    return -0x7fffbffb;
  }
  iVar2 = (*DAT_00aba21c)(0,param_4,param_5,param_1 + 0xc);
  if (-1 < iVar2) {
    *(undefined4 *)(param_1 + 8) = 1;
    *(undefined4 *)(param_1 + 0x10) = unaff_EDI;
    *(undefined4 *)(param_1 + 0x14) = unaff_ESI;
    uVar3 = (*(code *)**(undefined4 **)(param_1 + 0x24))((*(undefined4 **)(param_1 + 0x24))[6]);
    *(undefined8 *)(param_1 + 0x18) = uVar3;
    *(undefined4 *)(param_1 + 0x20) = 0;
    SetEvent(*(HANDLE *)(param_1 + 600));
    FUN_0056dac0(iVar1);
    iVar2 = 0;
  }
  return iVar2;
}

