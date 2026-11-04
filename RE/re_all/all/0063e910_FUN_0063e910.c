
void __thiscall
FUN_0063e910(int param_1,int param_2,undefined4 param_3,float *param_4,float *param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  float local_80;
  float local_7c;
  float local_78;
  undefined4 local_74;
  float local_70;
  float local_6c;
  float local_68;
  undefined4 local_64;
  undefined1 local_60 [48];
  undefined1 local_30 [48];
  
  if (param_2 != 0) {
    iVar1 = *(int *)(param_1 + 0x18);
    uVar2 = *(undefined4 *)(iVar1 + 0x150);
    iVar3 = *(int *)(param_1 + 0x14);
    uVar4 = *(undefined4 *)(iVar3 + 0x150);
    local_78 = param_5[2] - *(float *)(iVar1 + 0x3c);
    local_7c = param_5[1] - *(float *)(iVar1 + 0x38);
    local_80 = *param_5 - *(float *)(iVar1 + 0x34);
    local_74 = 0;
    local_68 = param_4[2] - *(float *)(iVar3 + 0x3c);
    local_6c = param_4[1] - *(float *)(iVar3 + 0x38);
    local_70 = *param_4 - *(float *)(iVar3 + 0x34);
    local_64 = 0;
    FUN_005f5190(local_60,0x10,3,FUN_0061ddb0);
    FUN_005fc650(iVar1 + 4,iVar1 + 0x14,iVar1 + 0x24,iVar1 + 8,iVar1 + 0x18,iVar1 + 0x28,iVar1 + 0xc
                 ,iVar1 + 0x1c,iVar1 + 0x2c);
    iVar1 = *(int *)(param_1 + 0x14);
    FUN_005fc650(iVar1 + 4,iVar1 + 0x14,iVar1 + 0x24,iVar1 + 8,iVar1 + 0x18,iVar1 + 0x28,iVar1 + 0xc
                 ,iVar1 + 0x1c,iVar1 + 0x2c);
    FUN_00640380(local_30,local_60,&local_70,&local_80,param_3,*(int *)(param_1 + 0x14) + 0x194,
                 uVar4,*(int *)(param_1 + 0x18) + 0x194,uVar2);
  }
  return;
}

