
undefined4
FUN_0054ee60(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
            int param_6,int param_7,undefined4 *param_8,int *param_9,undefined4 param_10)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  undefined4 *puVar7;
  int local_8a8;
  undefined1 local_8a4 [20];
  code *pcStack_890;
  int local_88c;
  char acStack_888 [3];
  char cStack_885;
  char cStack_884;
  char cStack_883;
  char cStack_87d;
  int iStack_878;
  int iStack_874;
  int iStack_870;
  int iStack_86c;
  int iStack_868;
  uint uStack_460;
  uint uStack_45c;
  int iStack_458;
  int iStack_454;
  undefined4 auStack_448 [273];
  
  local_8a8 = 0;
  if (param_5 == 0) {
    local_8a8 = (**(code **)(param_1 + 0x30))(param_2,0,1,0);
    if (local_8a8 == 0) {
      return 0xffffffff;
    }
    iVar2 = param_1 + 100;
    local_88c = local_8a8;
  }
  else {
    local_88c = FUN_0052d000(param_3,param_4);
    if (local_88c == 0) {
      return 0xffffffff;
    }
    iVar2 = param_1 + 0x7c;
  }
  FUN_0056d420(local_8a4,iVar2,0x18);
  iVar2 = FUN_00540df0(param_1,local_8a4,acStack_888);
  if (iVar2 != 0) {
LAB_0054f0c6:
    if (param_5 == 0) {
      (**(code **)(param_1 + 0x34))(local_8a8);
      return 0xffffffff;
    }
    (*pcStack_890)(local_88c);
    return 0xffffffff;
  }
  if (param_5 != 0) {
    (*pcStack_890)(local_88c);
  }
  if (*(int *)(param_1 + 0x2c) == 0) {
    if (param_7 == 1) {
      FUN_00546d90(acStack_888,1);
      FUN_00541150(acStack_888);
    }
    if (*(int *)(param_1 + 0x94) != 0) {
      if ((cStack_87d == '\0') && (*(int *)(param_1 + 0x98) == 1)) {
        if ((acStack_888[0] != '\0') && (iVar2 = FUN_00546d90(acStack_888,1), iVar2 < 0)) {
          return 0xffffffff;
        }
        if (((((cStack_883 != ' ') || (cStack_884 != '\x04')) || (cStack_885 != '\0')) ||
            ((iStack_868 != 0 || (iStack_86c != -0x1000000)))) ||
           ((iStack_878 != 0xff0000 || ((iStack_874 != 0xff00 || (iStack_870 != 0xff)))))) {
          pcVar5 = acStack_888;
          puVar7 = auStack_448;
          for (iVar2 = 0x110; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar7 = *(undefined4 *)pcVar5;
            pcVar5 = pcVar5 + 4;
            puVar7 = puVar7 + 1;
          }
          FUN_00546c90(uStack_460,uStack_45c,acStack_888);
          FUN_0054ecc0(0,0,auStack_448,acStack_888);
          FUN_005421c0(auStack_448);
        }
        uVar1 = *(uint *)(param_1 + 0x9c);
        uVar6 = 0;
        if (uStack_45c != 0) {
          do {
            puVar3 = (uint *)(iStack_458 * uVar6 + iStack_454);
            uVar4 = 0;
            if (uStack_460 != 0) {
              do {
                if (*puVar3 == (uVar1 | 0xff000000)) {
                  *puVar3 = 0;
                }
                uVar4 = uVar4 + 1;
                puVar3 = puVar3 + 1;
              } while (uVar4 < uStack_460);
            }
            uVar6 = uVar6 + 1;
          } while (uVar6 < uStack_45c);
        }
      }
      else {
        FUN_0054ecf0(acStack_888);
      }
    }
    if (param_6 != 0) {
      FUN_00546d90(acStack_888,1);
      iVar2 = FUN_0056e030(0x42c,"..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",0x489);
      *param_9 = iVar2;
      if (iVar2 == 0) {
        FUN_0056e1d0(iStack_454);
        goto LAB_0054f0c6;
      }
      iVar2 = FUN_0054e820(acStack_888,iVar2,param_10,0,0);
      if (iVar2 == -1) {
        FUN_0056e1d0(iStack_454);
        FUN_0056e1d0(*param_9);
      }
      else if (iVar2 == 1) {
        FUN_0056e1d0(iStack_454);
      }
      goto LAB_0054f13f;
    }
  }
  pcVar5 = acStack_888;
  for (iVar2 = 0x110; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_8 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    param_8 = param_8 + 1;
  }
LAB_0054f13f:
  if (param_5 == 0) {
    (**(code **)(param_1 + 0x34))(local_8a8);
  }
  return 0;
}

