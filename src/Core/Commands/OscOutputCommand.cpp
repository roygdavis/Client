#include "OscOutputCommand.h"

#include "Global.h"

OscOutputCommand::OscOutputCommand(QObject* parent)
    : AbstractCommand(parent),
      output(Osc::DEFAULT_OUTPUT), path(""), message(""), type("")
{
}

const QString& OscOutputCommand::getOutput() const
{
    return this->output;
}

const QString& OscOutputCommand::getPath() const
{
    return this->path;
}

const QString& OscOutputCommand::getMessage() const
{
    return this->message;
}

const QString& OscOutputCommand::getType() const
{
    return this->type;
}

void OscOutputCommand::setOutput(const QString& output)
{
    this->output = output;
    emit outputChanged(this->output);
}

void OscOutputCommand::setPath(const QString& path)
{
    this->path = path;
    emit pathChanged(this->path);
}

void OscOutputCommand::setMessage(const QString& message)
{
    this->message = message;
    emit messageChanged(this->message);
}

void OscOutputCommand::setType(const QString& type)
{
    this->type = type;
    emit typeChanged(this->type);
}

void OscOutputCommand::readProperties(boost::property_tree::wptree& pt)
{
    AbstractCommand::readProperties(pt);

    setOutput(QString::fromStdWString(pt.get(L"output", Osc::DEFAULT_OUTPUT.toStdWString())));
    setPath(QString::fromStdWString(pt.get(L"path", L"")));
    setMessage(QString::fromStdWString(pt.get(L"message", L"")));
    setType(QString::fromStdWString(pt.get(L"type", L"")));
}

void OscOutputCommand::writeProperties(QXmlStreamWriter* writer)
{
    AbstractCommand::writeProperties(writer);

    writer->writeTextElement("output", this->getOutput());
    writer->writeTextElement("path", this->getPath());
    writer->writeTextElement("message", this->getMessage());
    writer->writeTextElement("type", this->getType());
}