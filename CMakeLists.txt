juce_add_modules(
    INSTALL_PATH "include/NEWDNA-0.1.0/modules"
    ALIAS_NAMESPACE newDNA
    newdna_dsp
    newdna_fx)

    add_subdirectory(newdna_dsp
    newdna_fx
    rewrite)