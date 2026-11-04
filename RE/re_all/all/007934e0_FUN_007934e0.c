
void __thiscall FUN_007934e0(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  int iVar3;
  int *unaff_EDI;
  int iVar4;
  undefined1 auStack_74 [4];
  undefined1 auStack_70 [4];
  float fStack_6c;
  float fStack_68;
  undefined8 uStack_64;
  int *local_5c;
  float fStack_58;
  undefined8 uStack_54;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  int iStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  undefined4 uStack_30;
  
  local_5c = param_1;
  uStack_54._4_4_ = (**(code **)(*param_1 + 0x18))();
  iVar4 = 0;
  fStack_48 = (float)param_1[1];
  fStack_44 = (float)param_1[2];
  iStack_40 = param_1[3];
  fStack_3c = (float)param_1[4];
  if (0 < uStack_54._4_4_) {
    do {
      (**(code **)(*local_5c + 0xc))(auStack_70,&fStack_4c,&uStack_54);
      if (unaff_EBX == 0) {
        if (iVar4 == 2) {
          iVar3 = 0;
          if (0 < (int)&fStack_68) {
            do {
              iVar1 = iVar3 * (int)&fStack_6c;
              iVar2 = *(int *)((int)&uStack_64 + iVar1 + 4) * (int)auStack_74;
              uStack_54._0_4_ = (float)uStack_64 * (float)*(int **)((int)&local_5c + iVar2);
              fStack_58 = fStack_68 * *(float *)((int)&uStack_64 + iVar2 + 4);
              local_5c = (int *)(fStack_6c * *(float *)((int)&uStack_64 + iVar2));
              uStack_54._4_4_ = 0;
              iVar2 = (int)*(int **)((int)&local_5c + iVar1) * (int)auStack_74;
              fStack_44 = (float)uStack_64 * (float)*(int **)((int)&local_5c + iVar2);
              fStack_48 = fStack_68 * *(float *)((int)&uStack_64 + iVar2 + 4);
              fStack_4c = fStack_6c * *(float *)((int)&uStack_64 + iVar2);
              iStack_40 = 0;
              iVar1 = (int)*(float *)((int)&fStack_58 + iVar1) * (int)auStack_74;
              fStack_34 = (float)uStack_64 * (float)*(int **)((int)&local_5c + iVar1);
              fStack_38 = fStack_68 * *(float *)((int)&uStack_64 + iVar1 + 4);
              fStack_3c = fStack_6c * *(float *)((int)&uStack_64 + iVar1);
              uStack_30 = 0;
              (**(code **)(*param_2 + 4))(&local_5c,2,iVar3);
              iVar3 = iVar3 + 1;
            } while (iVar3 < (int)&fStack_68);
          }
        }
        else if ((iVar4 == 3) && (iVar3 = 0, 0 < (int)&fStack_68)) {
          do {
            iVar1 = iVar3 * (int)&fStack_6c;
            iVar2 = (uint)*(ushort *)((int)&uStack_64 + iVar1 + 4) * (int)auStack_74;
            uStack_54._0_4_ = (float)uStack_64 * (float)*(int **)((int)&local_5c + iVar2);
            fStack_58 = fStack_68 * *(float *)((int)&uStack_64 + iVar2 + 4);
            local_5c = (int *)(fStack_6c * *(float *)((int)&uStack_64 + iVar2));
            uStack_54._4_4_ = 0;
            iVar2 = (uint)*(ushort *)((int)&uStack_64 + iVar1 + 6) * (int)auStack_74;
            fStack_44 = (float)uStack_64 * (float)*(int **)((int)&local_5c + iVar2);
            fStack_48 = fStack_68 * *(float *)((int)&uStack_64 + iVar2 + 4);
            fStack_4c = fStack_6c * *(float *)((int)&uStack_64 + iVar2);
            iStack_40 = 0;
            iVar1 = (uint)*(ushort *)((int)&local_5c + iVar1) * (int)auStack_74;
            fStack_34 = (float)uStack_64 * (float)*(int **)((int)&local_5c + iVar1);
            fStack_38 = fStack_68 * *(float *)((int)&uStack_64 + iVar1 + 4);
            fStack_3c = fStack_6c * *(float *)((int)&uStack_64 + iVar1);
            uStack_30 = 0;
            (**(code **)(*param_2 + 4))(&local_5c,3,iVar3);
            iVar3 = iVar3 + 1;
          } while (iVar3 < (int)&fStack_68);
        }
      }
      else if (unaff_EBX == 1) {
        if (iVar4 == 2) {
          iVar3 = 0;
          if (0 < (int)&fStack_68) {
            do {
              iVar1 = iVar3 * (int)&fStack_6c;
              iVar2 = *(int *)((int)&uStack_64 + iVar1 + 4) * (int)auStack_74;
              uStack_54._0_4_ = (float)*(double *)((int)&uStack_54 + iVar2) * (float)uStack_64;
              fStack_58 = (float)*(double *)((int)&local_5c + iVar2) * fStack_68;
              local_5c = (int *)((float)*(double *)((int)&uStack_64 + iVar2) * fStack_6c);
              uStack_54._4_4_ = 0;
              iVar2 = (int)*(int **)((int)&local_5c + iVar1) * (int)auStack_74;
              fStack_44 = (float)*(double *)((int)&uStack_54 + iVar2) * (float)uStack_64;
              fStack_48 = (float)*(double *)((int)&local_5c + iVar2) * fStack_68;
              fStack_4c = (float)*(double *)((int)&uStack_64 + iVar2) * fStack_6c;
              iStack_40 = 0;
              iVar1 = (int)*(float *)((int)&fStack_58 + iVar1) * (int)auStack_74;
              fStack_34 = (float)*(double *)((int)&uStack_54 + iVar1) * (float)uStack_64;
              fStack_38 = (float)*(double *)((int)&local_5c + iVar1) * fStack_68;
              fStack_3c = (float)*(double *)((int)&uStack_64 + iVar1) * fStack_6c;
              uStack_30 = 0;
              (**(code **)(*param_2 + 4))(&local_5c,2,iVar3);
              iVar3 = iVar3 + 1;
            } while (iVar3 < (int)&fStack_68);
          }
        }
        else if ((iVar4 == 3) && (iVar3 = 0, 0 < (int)&fStack_68)) {
          do {
            iVar1 = iVar3 * (int)&fStack_6c;
            iVar2 = (uint)*(ushort *)((int)&uStack_64 + iVar1 + 4) * (int)auStack_74;
            uStack_54._0_4_ = (float)*(double *)((int)&uStack_54 + iVar2) * (float)uStack_64;
            fStack_58 = (float)*(double *)((int)&local_5c + iVar2) * fStack_68;
            local_5c = (int *)((float)*(double *)((int)&uStack_64 + iVar2) * fStack_6c);
            uStack_54._4_4_ = 0;
            iVar2 = (uint)*(ushort *)((int)&uStack_64 + iVar1 + 6) * (int)auStack_74;
            fStack_44 = (float)*(double *)((int)&uStack_54 + iVar2) * (float)uStack_64;
            fStack_48 = (float)*(double *)((int)&local_5c + iVar2) * fStack_68;
            fStack_4c = (float)*(double *)((int)&uStack_64 + iVar2) * fStack_6c;
            iStack_40 = 0;
            iVar1 = (uint)*(ushort *)((int)&local_5c + iVar1) * (int)auStack_74;
            fStack_34 = (float)*(double *)((int)&uStack_54 + iVar1) * (float)uStack_64;
            fStack_38 = (float)*(double *)((int)&local_5c + iVar1) * fStack_68;
            fStack_3c = (float)*(double *)((int)&uStack_64 + iVar1) * fStack_6c;
            uStack_30 = 0;
            (**(code **)(*param_2 + 4))(&local_5c,3,iVar3);
            iVar3 = iVar3 + 1;
          } while (iVar3 < (int)&fStack_68);
        }
      }
      (**(code **)(*unaff_EDI + 0x14))(iVar4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < uStack_54._4_4_);
  }
  return;
}

